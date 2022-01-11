//
// Created by Sharper8 on 07/09/2023.
//

#include <cmath>
#include "Spaceship.h"

Spaceship::Spaceship(double x, double y, double angle, double size,double xSpeed, double ySpeed) {
    this->x = x;
    this->y = y;
    this->shipSize = size;
    this->angle = angle;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->speed = 0;
}

// destructeur
Spaceship::~Spaceship(){}

//getters
double Spaceship::GetX() {
    return x;
}

double Spaceship::GetY() {
    return y;
}

double Spaceship::GetXSpeed() {
    return xSpeed;
}

double Spaceship::GetYSpeed() {
    return ySpeed;
}

double Spaceship::GetAngle() {
    return angle;
}

double Spaceship::GetSpeed() {
    return speed;
}

//setters

void Spaceship::SetX(double xSpeed) {
    this->x = xSpeed;
}

void Spaceship::SetY(double ySpeed) {
    this->y = ySpeed;
}

void Spaceship::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Spaceship::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}

void Spaceship::SetSpeed(double speed) {
    this->speed = speed;
}

//movement voector
void Spaceship::updateSpeed() {
    xSpeed = speed * cos(angle);
    ySpeed = speed * sin(angle);
}


//move

void Spaceship::Move() {

    x += 1* cos(angle)+50;
    y += 1* sin(angle)+50;
}

void Spaceship::Move(double screenWidth, double screenHeight) {
    x += xSpeed;
    y += ySpeed;

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
}


