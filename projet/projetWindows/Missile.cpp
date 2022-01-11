//
// Created by Sharper8 on 11/09/2023.
//

#include "Missile.h"

//
// Created by Sharper8 on 07/09/2023.
//
#include "Missile.h"


Missile::Missile(double x, double y, double size, double xSpeed, double ySpeed) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;

}

//getters
double Missile::GetX() {
    return x;
}

double Missile::GetY() {
    return y;
}

double Missile::GetXSpeed() {
    return xSpeed;
}

double Missile::GetYSpeed() {
    return ySpeed;
}

//setters
void Missile::SetX(double xSpeed) {
    this->x = xSpeed;
}

void Missile::SetY(double ySpeed) {
    this->y = ySpeed;
}

void Missile::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Missile::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void Missile::SetSize(double size) {
    this->size = size;
}

//move
void Missile::Move() {
    x += xSpeed;
    y += ySpeed;
//    framework.DrawAsteroid(framework.GetScreenWidth()/2, framework.GetScreenHeight()/2, 10);

}

void Missile::Move(double screenWidth, double screenHeight) {
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

Missile::~Missile() {

}

double Missile::GetSize() {
    return size;
}

