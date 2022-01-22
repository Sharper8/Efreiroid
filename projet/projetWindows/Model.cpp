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
#include "missile.h"
#include "asteroid.h"
#include "spaceship.h"
using namespace std;

// constructor
Model::Model(int screenWidth, int screenHeight, int shipSize, int missileSize, Framework *framework) {
    //DEBUG values
    this->debug = false;
    this->isRunning = true;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->framework = framework;
    this->missilesize = missileSize;

    //initialisation of the random
    srand(static_cast<unsigned>(time(NULL)));

    //define spaceship
    this->spaceship = new Spaceship(screenWidth / 2, screenHeight / 2, shipSize, 0, 0, 0);
    //vector for missiles
    this->missileList = vector<Missile*> ();

    //init a list of asteroids with random speed, size and position
    this-> asteroidList = vector<Asteroid*> ();
    double tabDirections [2] = {1, -1};
    for (int i = 0; i < 10; ++i) {
        int x = rand() % screenWidth;
        int y = rand() % screenHeight;
        int size = rand() % 100 + 50;
        asteroidList.push_back(new Asteroid(x, y,size, tabDirections[rand() % 2] * (rand() % 15 + 2),tabDirections[rand() % 2] * (rand() % 10 + 2)));
    }
}

//function to transform deg in rad
double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

void Model::setIsRunning(bool running) {
    this->isRunning = running;
}

void Model::accelerate() {
    double new_xSpeed = spaceship->GetXSpeed() + cos(deg2rad(spaceship->GetAngle())) * 1.35;
    double new_ySpeed = spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())) * 1.35;
    spaceship->SetXSpeed(new_xSpeed);
    spaceship->SetYSpeed(new_ySpeed);
}

// methods
void Model::decelerate() {
        double new_ySpeed = spaceship->GetYSpeed() - sin(deg2rad(spaceship->GetAngle())) * 1.35;
        double new_xSpeed = spaceship->GetXSpeed() - cos(deg2rad(spaceship->GetAngle())) * 0.65;
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
    auto TEST = new Missile(xpos, ypos, this->missilesize, xspeed, yspeed);
    missileList.push_back(TEST);
}

void Model::update() {
    //check for collisions in both lists
    for (int i = 0 ; i<asteroidList.size();++i){
        for (int j = 0; j < missileList.size(); ++j) {
            if (FlyingObject::Collide(asteroidList[i], missileList[j])) {
                // delete the asteroid and the missile
                delete asteroidList[i];
                delete missileList[j];
                asteroidList.erase(asteroidList.begin()+i);
                missileList.erase(missileList.begin()+j);
            }
        }
    }
    //update elements on the canvas
    spaceship->Move(screenWidth, screenHeight);
    for (int i = 0; i < asteroidList.size(); ++i) {
        asteroidList[i]->Move(screenWidth, screenHeight);
    }
    for (int i = 0; i < missileList.size(); ++i) {
        missileList[i]->Move(screenWidth, screenHeight);
    }
    framework->Update();
}

vector<FlyingObject *> Model::getAllFlyingObjects() {
    //return the list of all the flying objects
    vector<FlyingObject *> allFlyingObjects;
    allFlyingObjects.push_back(spaceship);
    for (int i = 0; i < asteroidList.size(); ++i) {
        allFlyingObjects.push_back(asteroidList[i]);
    }
    for (int i = 0; i < missileList.size(); ++i) {
        allFlyingObjects.push_back(missileList[i]);
    }
    return allFlyingObjects;
}

Model::~Model() {
    //delete all the elements of the lists
    delete spaceship;
    for (int i = 0; i < asteroidList.size(); ++i) {
        delete asteroidList[i];
    }
    for (int i = 0; i < missileList.size(); ++i) {
        delete missileList[i];
    }
}
