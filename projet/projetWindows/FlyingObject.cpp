//
// Created by Sharper8 on 18/09/2023.
//

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
double FlyingObject::GetX() {
    return x;
}

double FlyingObject::GetY() {
    return y;
}

double FlyingObject::GetXSpeed() {
    return xSpeed;
}

double FlyingObject::GetYSpeed() {
    return ySpeed;
}

double FlyingObject::GetSize() {
    return size;
}

//setters
void FlyingObject::SetX(double xSpeed) {
    this->x = xSpeed;
}

void FlyingObject::SetY(double ySpeed) {
    this->y = ySpeed;
}

void FlyingObject::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void FlyingObject::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}

//move
void FlyingObject::Move() {
    x += xSpeed;
    y += ySpeed;
//    framework.DrawAsteroid(framework.GetScreenWidth()/2, framework.GetScreenHeight()/2, 10);

}

void FlyingObject::Move(double screenWidth, double screenHeight) {
    // -------
    y += ySpeed;
    x += xSpeed;
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

FlyingObject::~FlyingObject() {
}

double FlyingObject::GetAngle() {
    return angle;
}

void FlyingObject::SetAngle(double d) {
    this->angle = d;
}

bool FlyingObject::Collide(FlyingObject *o1, FlyingObject *o2) {
    // delete both objects if they collide
    // -------
    double distance = sqrt(pow(o1->GetX() - o2->GetX(), 2) + pow(o1->GetY() - o2->GetY(), 2));
    return distance < o1->GetSize() + o2->GetSize();
}
