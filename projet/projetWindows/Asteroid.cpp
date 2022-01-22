//
// Created by Sharper8 on 07/09/2023.
//
#include "Asteroid.h"


Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed): FlyingObject(x, y, size, xSpeed, ySpeed){}

string Asteroid::GetTypeName() {
    return "Asteroid";
}