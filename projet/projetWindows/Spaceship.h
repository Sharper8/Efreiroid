//
// Created by Sharper8 on 07/09/2023.
//
#include "FlyingObject.h"

#ifndef SDLTEST_SPACESHIP_H
#define SDLTEST_SPACESHIP_H
using namespace std;
#include <chrono>

class Spaceship: public FlyingObject {
private:
    double shield= 1.0;
    bool invincible = false;
    std::chrono::time_point<std::chrono::steady_clock> invincibilityEndTime;
public:
    bool warning = false;
    // Constructor
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle);
    string GetTypeName() override;
    double GetShield() const;
    void SetShield(double i);
    bool GetInvincible() const;
    void accelerate();
    void decelerate();
    void rotate(int angle);
    void SetInvincibleFor(double duration);
    void UpdateInvincibilityStatus();
};


#endif //SDLTEST_SPACESHIP_H
