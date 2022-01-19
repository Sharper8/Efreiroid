//
// Created by Sharper8 on 18/09/2023.
//

#include "FlyingObject.h"

//constyructeur

FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;

}
//getters
double FlyingObject::GetX() {
    return x;
}

double FlyingObject::GetY() {
    return y;
}

double FlyingObject::GetXSpeed() {
    return xSpeed;
}

double FlyingObject::GetYSpeed() {
    return ySpeed;
}

double FlyingObject::GetSize() {
    return size;
}

//setters
void FlyingObject::SetX(double xSpeed) {
    this->x = xSpeed;
}

void FlyingObject::SetY(double ySpeed) {
    this->y = ySpeed;
}

void FlyingObject::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void FlyingObject::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}

//move
void FlyingObject::Move() {
    x += xSpeed;
    y += ySpeed;
//    framework.DrawAsteroid(framework.GetScreenWidth()/2, framework.GetScreenHeight()/2, 10);

}

void FlyingObject::Move(double screenWidth, double screenHeight) {
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    y += ySpeed;
    x += xSpeed;
    if (x > screenWidth) {
        x = 0;
    }
    if (x < 0) {
        x = screenWidth;
    }
    if (y > screenHeight) {
        y = 0;
    }

    if (y < 0) {
        y = screenHeight;
    }
    if (y > screenWidth) {
        y = 0;
    }
}

FlyingObject::~FlyingObject() {
}

double FlyingObject::GetSize() {
    return size;
}
