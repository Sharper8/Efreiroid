//
// Created by Sharper8 on 07/09/2023.
//
#include "Missile.h"


Missile::Missile(double x, double y,double size, double xSpeed, double ySpeed,double angle):FlyingObject(x, y, size, xSpeed, ySpeed,angle){}

void Missile::Move(double screenWidth, double screenHeight) {
    y += ySpeed;
    x += xSpeed;
    // -------TODO implémenter la destruction en sortie
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

string Missile::GetTypeName() {
    return "Missile";
}
