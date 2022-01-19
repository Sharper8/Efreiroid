//
// Created by Sharper8 on 06/10/2023.
//

#include "View.h"


void View::draw() {

    //show missile on canvas
    for (int i = 0; i < missileList.size(); ++i) {
        missileList[i]->Move(screenWidth, screenHeight);
        framework.DrawMissile(missileList[i]->GetX(), missileList[i]->GetY());
    }
    framework.DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle()+90, 0, false);
    framework.Update();
}