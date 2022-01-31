//
// Created by Sharper8 on 11/09/2023.
//

#include "FlyingObject.h"

#ifndef SDLTEST_MISSILE_H
#define SDLTEST_MISSILE_H


class Missile:public FlyingObject {
    double size = size;
    bool outOfScreen = false;

public:

    Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle);

    void Move(double screenWidth, double screenHeight) override;
    string GetTypeName() override;
    bool GetOutofScreen();
};


#endif //SDLTEST_MISSILE_H
