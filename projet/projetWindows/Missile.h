//
// Created by Sharper8 on 11/09/2023.
//

                        ////////////////////////////////////////
                        // Description of the class objective //
                        ////////////////////////////////////////
// The Missile class is a child class of FlyingObject. It is used to represent the missiles shot by the spaceship,
// and used to destroy asteroids. The difference with other flying objects is that missiles are destroyed when they go
// out of the screen.
#include "FlyingObject.h"

#ifndef SDLTEST_MISSILE_H
#define SDLTEST_MISSILE_H


class Missile:public FlyingObject {
private:
    bool outOfScreen;

public:
    Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle);
    void Move(double screenWidth, double screenHeight) override;
    string GetTypeName() override;
    [[nodiscard]] bool getOutOfScreen() const;
};


#endif //SDLTEST_MISSILE_H
