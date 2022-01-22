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

    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);
    string GetTypeName() override;
};

#endif //SDLTEST_ASTEROID_H
