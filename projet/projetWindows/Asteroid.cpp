//
// Created by Sharper8 on 07/09/2023.
//
#include "Asteroid.h"


Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;

}

//destructeur
Asteroid::~Asteroid(){}

//getters
double Asteroid::GetX() {
    return x;
}

double Asteroid::GetY() {
    return y;
}

double Asteroid::GetXSpeed() {
    return xSpeed;
}

double Asteroid::GetYSpeed() {
    return ySpeed;
}

double Asteroid::GetSize() {
    return size;
}

//setters
void Asteroid::SetX(double xSpeed) {
    this->x = xSpeed;
}

void Asteroid::SetY(double ySpeed) {
    this->y = ySpeed;
}

void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void Asteroid::SetSize(double size) {
    this->size = size;
}

//move
void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
//    framework.DrawAsteroid(framework.GetScreenWidth()/2, framework.GetScreenHeight()/2, 10);

}

void Asteroid::Move(double screenWidth, double screenHeight) {
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

