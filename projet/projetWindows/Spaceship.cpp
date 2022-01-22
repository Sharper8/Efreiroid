//
// Created by Sharper8 on 07/09/2023.
//

#include <cmath>
#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle) : FlyingObject(x, y, size, xSpeed, ySpeed) {
    this->x = x;
    this->y = y;
    this->shipSize = size;
    this->angle = angle;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->speed = 0;
}

//move
//void Spaceship::Move() {
//
//    x += 1* cos(angle)+50;
//    y += 1* sin(angle)+50;
//    std::cout << "x : " << x << " y : " << y << std::endl;
//}

string Spaceship::GetTypeName() {
    return "Spaceship";
}

void Spaceship::Move(double screenWidth, double screenHeight) {
    //TODO : REMOVE IF OK
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
