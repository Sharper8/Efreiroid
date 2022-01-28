//
// Created by Sharper8 on 07/09/2023.
//
#include "FlyingObject.h"

#ifndef SDLTEST_SPACESHIP_H
#define SDLTEST_SPACESHIP_H


class Spaceship:public FlyingObject {
    private:
        int shield= 10;

    public:
    // Constructor
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle);
    string GetTypeName() override;
    int GetShield();
    void SetShield(int i);
};


#endif //SDLTEST_SPACESHIP_H
