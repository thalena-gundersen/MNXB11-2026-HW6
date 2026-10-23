#include <cmath>
#include "MovingObject.h"
ClassImp(MovingObject);

// Task 1.2: MovingObject Class Implementation

// Constructors

// Default constructor

MovingObject::MovingObject()
    : fVx{0.0}, fVy{0.0}, fVz{0.0} {
    }

// Parameterised constructor

MovingObject::MovingObject(Double_t vx, Double_t vy, Double_t vz)
    : fVx{vx}, fVy{vy}, fVz{vz} {
    }

// Destructor 

MovingObject::~MovingObject() {
}

// Getters

// Component getters

Double_t MovingObject::Vx() const {
    return fVx;
}

Double_t MovingObject::Vy() const {
    return fVy;
}

Double_t MovingObject::Vz() const {
    return fVz;
}

//  Speed getters

Double_t MovingObject::Speed() const {
    return std::sqrt((fVx * fVx) + (fVy * fVy) + (fVz * fVz));
}

Double_t MovingObject::HorizontalSpeed() const {
    return std::sqrt((fVx * fVx) + (fVy * fVy));
}

// Setter

void MovingObject::SetVelocity(Double_t vx, Double_t vy, Double_t vz){
    fVx = vx;
    fVy = vy;
    fVz = vz;
}
