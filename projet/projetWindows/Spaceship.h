//
// Created by Sharper8 on 07/09/2023.
//
#include "FlyingObject.h"

#ifndef SDLTEST_SPACESHIP_H
#define SDLTEST_SPACESHIP_H


class Spaceship:public FlyingObject {

    double x;
    double y;
    double shipSize;
    double angle;
    double xSpeed;
    double ySpeed;
    double speed;

    public:

    // Constructor
    ///////////////
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle);

    /////////////////////////
    // Déplacement de l'objet
    // déplace selon le vecteur de vitesse de l'objet
    void Move(double screenWidth, double screenHeight) override;

    string GetTypeName() override;

    //void Move() override;
};


#endif //SDLTEST_SPACESHIP_H
