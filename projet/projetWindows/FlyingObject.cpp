//
// Created by Sharper8 on 18/09/2023.
//

                        ////////////////////////////////////////
                        // Description of the class objective //
                        ////////////////////////////////////////
// The FlyingObject class is the parent class of all the objects that can move in the game.
// It contains the position, the speed, the size and the angle of the object.

#include "FlyingObject.h"
#include <cmath>


//function to transform deg in rad
double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

//constructor
FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed,double angle) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->angle = angle;
}

//getters
double FlyingObject::GetX() const {
    return x;
}

double FlyingObject::GetY() const {
    return y;
}

double FlyingObject::GetXSpeed() const {
    return xSpeed;
}

double FlyingObject::GetYSpeed() const {
    return ySpeed;
}

double FlyingObject::GetSize() const {
    return size;
}

//setters
void FlyingObject::SetX(double d) {
    this->x = d;
}

void FlyingObject::SetY(double d) {
    this->y = d;
}

void FlyingObject::Move(double screenWidth, double screenHeight) {
    // move the object of it's xSpeed and ySpeed value
    y += ySpeed;
    x += xSpeed;
    //if the object is out of the screen, it appears on the other side
    if (x > screenWidth) {
        x = 0;
    }
    if (x < 0) {
        x = screenWidth;
    }
    if (y > screenHeight) {
        y = 0;
    }
    if (y < 0) {
        y = screenHeight;
    }
    if (y > screenWidth) {
        y = 0;
    }
}

FlyingObject::~FlyingObject() = default;

double FlyingObject::GetAngle() const {
    return angle;
}

bool FlyingObject::Collide(FlyingObject *o1, FlyingObject *o2) {
    // return true if the distance between the center of the two objects is smaller than the sum of their radius
    double distance = sqrt(pow(o1->GetX() - o2->GetX(), 2) + pow(o1->GetY() - o2->GetY(), 2));
    return distance < o1->GetSize()/2 + o2->GetSize()/2;
}
