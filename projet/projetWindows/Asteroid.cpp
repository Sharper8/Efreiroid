//
// Created by Sharper8 on 07/09/2023.
//
#include "Asteroid.h"
#include "FlyingObject.h"
#include <cmath>

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle): FlyingObject(x, y, size, xSpeed, ySpeed,angle){}

string Asteroid::GetTypeName() {
    return "Asteroid";
}

void Asteroid::Move(double screenWidth, double screenHeight) {
    this->SetX(this->GetX() + this->GetXSpeed());
    this->SetY(this->GetY() + this->GetYSpeed());
//    y += ySpeed;
//    x += xSpeed;
    if (x > screenWidth) {
        x=0;
    }
    if (x < 0) {
        x=screenWidth;
    }
    if (y > screenHeight) {
        y=0;
    }
    if (y < 0) {
        y=screenHeight;
    }
}