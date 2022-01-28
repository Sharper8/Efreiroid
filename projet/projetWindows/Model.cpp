//
// Created by Sharper8 on 06/10/2023.
//

#include "Model.h"
#include "View.h"
#include "framework.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
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
    //initialisation of the random
    srand(static_cast<unsigned>(time(NULL)));
    //define spaceship
    this->spaceship = new Spaceship(screenWidth / 2, screenHeight / 2, shipSize, 0, 0, 0);
    //vector for missiles
    this->missileList = vector<Missile*> ();
    //init a list of asteroids with random speed, size and position
    this-> asteroidList = vector<Asteroid*> ();
    // create a vector of vector that stores the coordinates of 9 even zones on the screen, exclude the middle of the screen
    vector<vector<int>> zones = {{screenWidth / 3, 0, 0, screenHeight / 3},
                                 {screenWidth / 3, 0, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth / 3, 0, screenHeight * 2 / 3, screenHeight},
                                 {screenWidth * 2 / 3, screenWidth, 0, screenHeight / 3},
                                 {screenWidth * 2 / 3, screenWidth, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth * 2 / 3, screenWidth, screenHeight * 2 / 3, screenHeight},
                                 {screenWidth, screenWidth * 2 / 3, 0, screenHeight / 3},
                                 {screenWidth, screenWidth * 2 / 3, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth, screenWidth * 2 / 3, screenHeight * 2 / 3, screenHeight}};
    //init random seed
    std::default_random_engine generator;//TODO changer ce truc ?
    // Create a uniform_int_distribution for choosing a random zone
    std::uniform_int_distribution<int> distribution(0, zones.size() - 1);
    //generate 10 asteroids
    for (int i = 0; i < 10; ++i) {
        // choose a random zone from the vector of zones with uniform_int_distribution() function
        // generate the random index
        int randomZoneIndex = distribution(generator);
        std::vector<int> selectedZone = zones[randomZoneIndex];
        //choose a random set of coordinates base on the zones coordinates of the chosen zone using uniform_real_distribution () funciton
        std::uniform_real_distribution<double> xDistribution(selectedZone[1], selectedZone[0]);
        std::uniform_real_distribution<double> yDistribution(selectedZone[2], selectedZone[3]);
        //generate a random angle between-180 and 180° using uniform_int_distribution
        double angle = distribution(generator) * 40 - 180;
        // Generate random x and y coordinates
        double X = xDistribution(generator);
        double Y = yDistribution(generator);
        double XSpeed = cos(deg2rad(angle))*5;
        double YSpeed = sin(deg2rad(angle))*5;
        //assign those random values and spawn the asteroid
        asteroidList.push_back(new Asteroid(X, Y,rand() % 100 + 50, XSpeed,YSpeed,angle));
    }
}

void Model::accelerate() {
    //TODO faire en sorte que la vitesse max soit 10
    double new_xSpeed = spaceship->GetXSpeed() + cos(deg2rad(spaceship->GetAngle())) * 2;
    double new_ySpeed = spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())) * 2;
    spaceship->SetXSpeed(new_xSpeed);
    spaceship->SetYSpeed(new_ySpeed);
}

// methods
void Model::decelerate() {
    //TODO faire en sorte que la vitesse max soit 10
        double new_ySpeed = spaceship->GetYSpeed() - sin(deg2rad(spaceship->GetAngle())) * 2;
        double new_xSpeed = spaceship->GetXSpeed() - cos(deg2rad(spaceship->GetAngle())) * 2;
        spaceship->SetXSpeed(new_xSpeed);
        spaceship->SetYSpeed(new_ySpeed);
}

void Model::rotate(int angle) {
    double new_angle = spaceship->GetAngle() + angle;
    spaceship->SetAngle(new_angle);
}

void Model::shoot() {
    //new missile object
    double xpos = spaceship->GetX();
    double ypos = spaceship->GetY();
    //base velocity of the missile
    double xspeed = spaceship->GetXSpeed() + cos(deg2rad(spaceship->GetAngle())) * 10;
    double yspeed = spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())) * 10;
//    auto msl = new Missile(xpos, ypos, missileSize, xspeed, yspeed, spaceship->GetAngle());
    missileList.push_back(new Missile(xpos, ypos, missileSize, xspeed, yspeed, spaceship->GetAngle()));
}

int Model::update() {
    //TODO pourquoi la luminosité change ou scintille en fonction du nbr d'asteroid
    framework->Update();
    //check for collisions in both lists
    for (int i = 0 ; i<asteroidList.size();++i){
        for (int j = 0; j < missileList.size(); ++j) {
            //collision between the missile and the asteroid
            if (FlyingObject::Collide(asteroidList[i], missileList[j])) {
                // delete the asteroid and the missile
                //if explosiosn left in asteroid
                if (asteroidList[i]->GetnBExplosionsLeft() <= 0) {
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
        if (!spaceship->GetInvincible()) {
            if (FlyingObject::Collide(asteroidList[i], spaceship)) {
                if (spaceship->GetShield() == 0) {
                    return -1;
                } else {
                    spaceship->SetShield(spaceship->GetShield() - 1);
                    spaceship->SetInvincibleFor(1);
                    //                spaceship->SetInvincibleFor(true);
                }
            }
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
//    framework->Update(); //todo reflechir si c'est mieux au dessus ou a la fin ( les return font que ça update pas)
    return 0;
}

vector<FlyingObject *> Model::getAllFlyingObjects() {
    //return the list of all the flying objects
    vector<FlyingObject *> allFlyingObjects;
    allFlyingObjects.push_back(spaceship);
//    vector<FlyingObject *> v(asteroidList.begin(), asteroidList.end()); TODO pourquoi ça marche pas ?
    for (auto & i : asteroidList) {
        allFlyingObjects.push_back(i);
    }
    for (auto & i : missileList) {
        allFlyingObjects.push_back(i);
    }
    return allFlyingObjects;
}

Model::~Model() = default;
