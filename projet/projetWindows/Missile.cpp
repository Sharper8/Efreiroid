//
// Created by Sharper8 on 07/09/2023.
//

                        ////////////////////////////////////////
                        // Description of the class objective //
                        ////////////////////////////////////////
// The Missile class is a child class of FlyingObject. It is used to represent the missiles shot by the spaceship,
// and used to destroy asteroids. The difference with other flying objects is that missiles are destroyed when they go
// out of the screen.

#include "Missile.h"
#include "FlyingObject.h"
#include <cmath>

Missile::Missile(double x, double y,double size, double xSpeed, double ySpeed,double angle): FlyingObject(x, y, size, xSpeed, ySpeed,angle) {
    outOfScreen = false;
    //the missile is shot in the direction of the spaceship, and following its speed
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
