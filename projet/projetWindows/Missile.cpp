//
// Created by Sharper8 on 07/09/2023.
//
#include "Missile.h"


Missile::Missile(double x, double y,double size, double xSpeed, double ySpeed) : FlyingObject(x, y, size, xSpeed, ySpeed) {}

void Missile::Move(double screenWidth, double screenHeight) {
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    y += ySpeed;
    x += xSpeed;
    if (x > screenWidth) {
        delete this;
    }
    if (x < 0) {
        delete this;
    }
    if (y > screenHeight) {
        delete this;
    }

    if (y < 0) {
        delete this;
    }
    if (y > screenWidth) {
        delete this;
    }
}

