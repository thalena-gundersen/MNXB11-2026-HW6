#include "MovingObject.h"

#include <TCanvas.h>
#include <TFile.h>
#include <TGraph.h>
#include <TH2D.h>
#include <TTree.h>

#include <iostream>


void read() {

    // Open ROOT file in READ mode
    TFile file("tree_file.root", "READ");

    // Check that file opened successfully
    if (file.IsZombie()) {
        std::cerr << "Error: Could not open ROOT file\n";
        return;
    }

    // Retrieve the tree named tree
    TTree *tree = nullptr;
    file.GetObject("tree", tree);

    // Check that TTRee exists
    if (tree == nullptr) {
        std::cerr << "Error: TTree does not exist\n";
        return;
    }

    // Initialise a MovingObject instance
    MovingObject *object = new MovingObject();

    // Set the address of the object branch
    tree->SetBranchAddress("object", &object);

    // Obtain the number of entries
    const Long64_t nEntries = tree->GetEntries();

    // Prepare a 2D histogram of vy versus vx
    TH2D histogram(
        "histogram",
        "Velocity components;v_{x} (m/x);v_{y} (m/s)",
        100, -1.5, 1.5,
        100, -1.5, 1.5 
    );

    histogram.SetDirectory(nullptr);

    // Loop over all measurements
    for (Long64_t i{0}; i < nEntries; ++i) {
        // Read current entry
        tree->GetEntry(i);

        // Fill histogram using the getters 
        histogram.Fill(object->Vx(), object->Vy());
    }

    // Create a canvas for the first plot
    TCanvas canvas1(
        "canvas1",
        "Velocity components",
        800, 600
    );

    // Draw the histogram
    histogram.Draw("COLZ");

    // Save the first plot
    canvas1.SaveAs("velocity_components.pdf");

    // Clean up
    tree->ResetBranchAddresses();
    delete object;
    file.Close();
}