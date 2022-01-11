//
// Created by Sharper8 on 07/09/2023.
//

#ifndef SDLTEST_ASTEROID_H
#define SDLTEST_ASTEROID_H


#include "FlyingObject.h"

class Asteroid: public FlyingObject {


public:
    ///////////////
    // Constructeur
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);
};

#endif //SDLTEST_ASTEROID_H
