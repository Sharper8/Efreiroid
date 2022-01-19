//
// Created by Sharper8 on 11/09/2023.
//

#include "FlyingObject.h"

#ifndef SDLTEST_MISSILE_H
#define SDLTEST_MISSILE_H


class Missile:public FlyingObject {
    double x = x;
    double y = y;
    double size = size;
    double xSpeed = xSpeed;
    double ySpeed = ySpeed;

public:

    Missile(double x, double y, double size, double xSpeed, double ySpeed);

//destructeur
    void Move(double screenWidth, double screenHeight);

};
#endif //SDLTEST_MISSILE_H
