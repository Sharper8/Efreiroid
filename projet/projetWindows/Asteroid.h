//
// Created by Sharper8 on 07/09/2023.
//

#include "FlyingObject.h"


#ifndef SDLTEST_ASTEROID_H
#define SDLTEST_ASTEROID_H

class Asteroid: public FlyingObject {
public:
    ///////////////
    // Constructeur
    // -------

    Asteroid(double x, double y, double size, double xSpeed, double ySpeed,double angle);
    string GetTypeName() override;
    void Move(double screenWidth, double screenHeight) override;

};

#endif //SDLTEST_ASTEROID_H
