//
// Created by Sharper8 on 06/10/2023.
//

#include "Model.h"
#include "View.h"
#include "framework.hpp"
#include <vector>
#include <cmath>
#include "missile.h"
#include "asteroid.h"
#include "spaceship.h"
#include "FlyingObject.h"

using namespace std;

// constructor
Model::Model(int screenWidth, int screenHeight, int shipSize, int missileSize, Framework *framework) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->framework = framework;
    this->missileSize = missileSize;
    //define spaceship
    this->spaceship = new Spaceship((double) screenWidth / 2, (double) screenHeight / 2, shipSize, 0, 0, 0);
    //vector for missiles
    this->missileList = vector<Missile*> ();
    //init a list of asteroids with random speed, size and position
    this-> asteroidList = vector<Asteroid*> ();
    //create 5 random asteroids
    for (int i = 0; i < 5; ++i) {
        //new random asteroid
        asteroidList.push_back(Asteroid::randomAsteroid(screenWidth, screenHeight));
    }
}

void Model::shoot() {
    if (missileList.size() > 2) {
        return;
    }
    //new missile object
    double xPos = spaceship->GetX();
    double yPos = spaceship->GetY();
    //base velocity of the missile
    double xSpeed = spaceship->GetXSpeed() + cos(deg2rad(spaceship->GetAngle())) * 10;
    double ySpeed = spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())) * 10;
    missileList.push_back(new Missile(xPos, yPos, missileSize, xSpeed, ySpeed, spaceship->GetAngle()));
}

int Model::update() {
    //if there is no asteroid left, the player wins
    if (asteroidList.empty()) {
        return 1;
    }
    framework->Update();
    //check for collisions in both lists
    for (int i = 0 ; i<asteroidList.size();++i){
        for (int j = 0; j < missileList.size(); ++j) {
            if (missileList[j]->getOutOfScreen()) {
                delete missileList[j];
                missileList.erase(missileList.begin() + j);
            }
            //collision between the missile and the asteroid
            if (FlyingObject::Collide(asteroidList[i], missileList[j])) {
                //if any explosion left in asteroid
                if (asteroidList[i]->getNbExplosionsLeft() <= 0) {
                    delete asteroidList[i];
                    asteroidList.erase(asteroidList.begin() + i);
                }
                else {
                    //create a new asteroid
                    Asteroid *newAsteroid = asteroidList[i]->Explode(missileList[j]->GetXSpeed(),
                                                                     missileList[j]->GetYSpeed());
                    //add it to the list
                    asteroidList.push_back(newAsteroid);
                }
                delete missileList[j];
                missileList.erase(missileList.begin() + j);
            }
        }
        //collision between the spaceship and the asteroid
        if (FlyingObject::Collide(asteroidList[i], spaceship)) {
            if (!spaceship->GetInvincible()) {
                if (spaceship->GetShield() <= 0.1) {
                    return -1;
                } else {
                    double newShield = spaceship->GetShield() - 0.2;
                    spaceship->SetShield(newShield);
                    spaceship->SetInvincibleFor(1);
                }
            }
            //no overlap, the asteroid bounce
//            spaceship->SetXSpeed(-spaceship->GetXSpeed());
//            spaceship->SetYSpeed(-spaceship->GetYSpeed());
//            asteroidList[i]->SetYSpeed(-asteroidList[i]->GetYSpeed());
//            asteroidList[i]->SetXSpeed(-asteroidList[i]->GetXSpeed());
        }
    }
    if (spaceship->GetInvincible()) {
        spaceship->UpdateInvincibilityStatus();
    }
    //update elements on the canvas
    spaceship->Move(screenWidth, screenHeight);
    for (auto & i : asteroidList) {
        i->Move(screenWidth, screenHeight);
    }
    for (auto & i : missileList) {
        i->Move(screenWidth, screenHeight);
    }
    return 0;
}

vector<FlyingObject *> Model::getAllFlyingObjects() {
//    return the list of all the flying objects
    std::vector<FlyingObject *> allFlyingObjects;
    std::copy(asteroidList.begin(), asteroidList.end(), std::back_inserter(allFlyingObjects));
    std::copy(missileList.begin(), missileList.end(), std::back_inserter(allFlyingObjects));
    allFlyingObjects.push_back(spaceship);
    return allFlyingObjects;
}

Model::~Model() {
    //delete all the elements of the lists
    //delete the spaceship
    delete spaceship;
    //delete the missiles
    for (auto & i : missileList) {
        delete i;
    }
    //delete the asteroids
    for (auto & i : asteroidList) {
        delete i;
    }
}

Spaceship *Model::getSpaceship() {
    return spaceship;
}

