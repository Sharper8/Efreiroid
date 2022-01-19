//
// Created by Sharper8 on 07/09/2023.
//

#include <cmath>
#include "Spaceship.h"

Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle) : FlyingObject(x, y, size, xSpeed, ySpeed) {
    this->x = x;
    this->y = y;
    this->shipSize = size;
    this->angle = angle;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->speed = 0;
}

double Spaceship::GetAngle() {
    return angle;
}


//setters

void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}

//movement vector
void Spaceship::updateSpeed() {
    xSpeed = speed * cos(angle);
    ySpeed = speed * sin(angle);
}


//move
void Spaceship::Move() {

    x += 1* cos(angle)+50;
    y += 1* sin(angle)+50;
}


