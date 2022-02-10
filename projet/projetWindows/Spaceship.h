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
    float shield = 1.0;
    bool invincible = false;
    std::chrono::time_point<std::chrono::steady_clock> invincibilityEndTime;
    bool warning = false;
public:
    // Constructor
    Spaceship(double x, double y, double size, double xSpeed, double ySpeed,double angle);
    string GetTypeName() override;
    float GetShield() const;
    void SetShield(float i);
    bool GetInvincible() const;
    void accelerate();
    void decelerate();
    void rotate(int angle);
    void SetInvincibleFor(double duration);
    void UpdateInvincibilityStatus();

    bool getWarning() const;
};


#endif //SDLTEST_SPACESHIP_H
