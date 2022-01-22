//
// Created by Sharper8 on 07/09/2023.
//

#include <cmath>
#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle) : FlyingObject(x, y, size, xSpeed, ySpeed) {
}

string Spaceship::GetTypeName() {
    return "Spaceship";
}

