//
// Created by Sharper8 on 07/09/2023.
//
#include "Missile.h"
#include "FlyingObject.h"
#include <cmath>

Missile::Missile(double x, double y,double size, double xSpeed, double ySpeed,double angle): FlyingObject(x, y, size, xSpeed, ySpeed,angle) {
    outOfScreen = false;
    this->xSpeed = xSpeed + cos(deg2rad(angle)) * 15;
    this->ySpeed = ySpeed + sin(deg2rad(angle)) * 15;
}

void Missile::Move(double screenWidth, double screenHeight) {
    y += ySpeed;
    x += xSpeed;
    //if the missile is out of the screen, it is destroyed
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) {
        outOfScreen = true;
    }
}

string Missile::GetTypeName() {
    return "Missile";
}

bool Missile::getOutOfScreen() const {
    return outOfScreen;
}
