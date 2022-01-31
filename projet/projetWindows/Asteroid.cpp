//
// Created by Sharper8 on 07/09/2023.
//
#include "Asteroid.h"
#include "FlyingObject.h"
#include <cmath>

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle): FlyingObject(x, y, size, xSpeed, ySpeed,angle){
    nbExplosionsLeft = size/100;
}

string Asteroid::GetTypeName() {
    return "Asteroid";
}

void Asteroid::Move(double screenWidth, double screenHeight) {
    this->SetX(this->GetX() + this->GetXSpeed());
    this->SetY(this->GetY() + this->GetYSpeed());
    if (x > screenWidth) {
        x=0;
    }
    if (x < 0) {
        x=screenWidth;
    }
    if (y > screenHeight) {
        y=0;
    }
    if (y < 0) {
        y=screenHeight;
    }
}

int Asteroid::GetnBExplosionsLeft() {
    return nbExplosionsLeft;
}

Asteroid* Asteroid::Explode(double xSpeed, double ySpeed) {
    size = size / 2;
    nbExplosionsLeft--;
    //change the speed of the new asteroids to be the same as the old one but with an impact of the missile
    this->xSpeed = 10*xSpeed/size;
    this->ySpeed = 10*ySpeed/size;
    //create a new asteroid
    auto *newAsteroid = new Asteroid(x, y, size, this->xSpeed+rand()%10-5, this->ySpeed+rand()%10-5,angle);
    //add it to the list
    return newAsteroid;

}
