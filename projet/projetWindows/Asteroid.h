//
// Created by Sharper8 on 07/09/2023.
//

#include "FlyingObject.h"


#ifndef SDLTEST_ASTEROID_H
#define SDLTEST_ASTEROID_H

class Asteroid: public FlyingObject {
private:
    int nbExplosionsLeft = 0;
public:
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed,double angle);
    string GetTypeName() override;
    void Move(double screenWidth, double screenHeight) override;
    int GetnBExplosionsLeft();
    Asteroid* Explode(double xSpeed, double ySpeed);


};

#endif //SDLTEST_ASTEROID_H
