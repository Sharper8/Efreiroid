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

    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    // * size : diamètre de l'objet
    // * x, y : position dans l'écran
    // -------
    // Constructeur
    ///////////////
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle);
    //Spaceship(double x, double y, double size, double xSpeed, double ySpeed);

    //////////
    // Getters
        double GetAngle();
        double GetSpeed();

    //////////
    // Setters
        void SetAngle(double size);
        void SetSpeed(double speed);

    /////////////////////////
    // Déplacement de l'objet
    // déplace selon le vecteur de vitesse de l'objet
        void Move();

    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
        void Move(double screenWidth, double screenHeight);

    void updateSpeed();

};


#endif //SDLTEST_SPACESHIP_H
