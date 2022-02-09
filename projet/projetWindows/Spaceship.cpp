//
// Created by Sharper8 on 07/09/2023.
//

#include <cmath>
#include "Spaceship.h"
#include <iostream>
using namespace std;

Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle) : FlyingObject(x, y, size, xSpeed, ySpeed,angle) {
}

string Spaceship::GetTypeName() {
    return "Spaceship";
}

double Spaceship::GetShield() const {
    return shield;
}
void Spaceship::SetShield(double i) {
    this->shield = i;
}

bool Spaceship::GetInvincible() const {
    return invincible;
}

void Spaceship::SetInvincibleFor(double duration) {
    this->invincible = true;
    //set invincibility end time "current time + duration (seconds)"
    invincibilityEndTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(static_cast<int>(duration * 1000));
    this->warning = true;
}

void Spaceship::UpdateInvincibilityStatus() {
    if (invincible && std::chrono::steady_clock::now() >= invincibilityEndTime) {
        invincible = false;
        warning = false;
    }
}


// methods
void Spaceship::accelerate() {
    double accFactor = 9.8;
    //define the absolute speed of the spaceship
    double new_xSpeed = xSpeed + cos(deg2rad(angle)) * 2;
    double new_ySpeed = ySpeed + sin(deg2rad(angle)) * 2;
    // if the speed is too high, set it to the max speed
    if (new_xSpeed > 10) {
        new_xSpeed = 10;
    }
    if (new_ySpeed > 10) {
        new_ySpeed = 10;
    }
    if (new_xSpeed < -10) {
        new_xSpeed = -10;
    }
    if (new_ySpeed < -10) {
        new_ySpeed = -10;
    }
    xSpeed = new_xSpeed;
    ySpeed= new_ySpeed;
}

void Spaceship::decelerate() {
    double new_xSpeed = xSpeed - cos(deg2rad(angle)) * 2;
    double new_ySpeed = ySpeed - sin(deg2rad(angle)) * 2;
    // if the speed is too high, set it to the max speed
    if (new_xSpeed > 10) {
        new_xSpeed = 10;
    }
    if (new_ySpeed > 10) {
        new_ySpeed = 10;
    }
    if (new_xSpeed < -10) {
        new_xSpeed = -10;
    }
    if (new_ySpeed < -10) {
        new_ySpeed = -10;
    }
    xSpeed = new_xSpeed;
    ySpeed= new_ySpeed;
}

void Spaceship::rotate(int angle) {
    double new_angle = this->angle + angle;
    this->angle = new_angle;
}
