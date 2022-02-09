//
// Created by Sharper8 on 06/10/2023.
//

#include "View.h"
#include "asteroid.h"
#include "spaceship.h"
#include "missile.h"

using namespace std;

View::View(Framework* framework) {
    this->framework = framework;
}

void View::update(vector<FlyingObject*> flyingObjectsList){
    //for each element in the list
    for (auto & i : flyingObjectsList) {
        //if the element is an asteroid
        if (i->GetTypeName() == "Asteroid") {
            //show asteroid on canvas
            framework->DrawAsteroid(i->GetX(), i->GetY(), i->GetSize());
        }
        //if the element is a missile
        if (i->GetTypeName() == "Missile"){
            //show missile on canvas
            framework->DrawMissile(i->GetX(), i->GetY());
        }
        //if the element is a spaceship
        if (i->GetTypeName() == "Spaceship") {
            //show spaceship on canvas
            framework->DrawShip(i->GetX(), i->GetY(), i->GetAngle()+90, ((Spaceship*)i)->GetShield(), ((Spaceship*)i)->warning);
            //dessin de ship
//            cout << "ship drawn" << endl;
         }
     }
//    framework->Update();
}