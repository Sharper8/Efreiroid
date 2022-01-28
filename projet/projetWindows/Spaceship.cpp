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

int Spaceship::GetShield() {
    return shield;
}
void Spaceship::SetShield(int i) {
    this->shield = i;
}

bool Spaceship::GetInvincible() {
    return invincible;
}

void Spaceship::SetInvincibleFor(double duration) {
    this->invincible = true;
    //set invincibility end time "cxurrent time + 2 seconds"
    invincibilityEndTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(static_cast<int>(duration * 1000));
    this->warning = true;
}

void Spaceship::UpdateInvincibilityStatus() {
    if (invincible && std::chrono::steady_clock::now() >= invincibilityEndTime) {

        invincible = false;
        warning = false;
    }
    //print how much time of invincibility is left
//    cout << "invincibility end time: " << std::chrono::duration_cast<std::chrono::milliseconds>(invincibilityEndTime - std::chrono::steady_clock::now()).count() << endl;

}

Spaceship::~Spaceship() = default;
//TODO shield rechargeable ?