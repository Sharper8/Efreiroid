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

    //initialisation of the random
    srand(static_cast<unsigned>(time(NULL)));

    //define spaceship
    this->spaceship = new Spaceship(screenWidth / 2, screenHeight / 2, shipSize, 0, 0, 90);
    //vector for missiles
    this->missileList = vector<Missile*> ();

    //init a list of asteroids with random speed, size and position
    this-> asteroidList = vector<Asteroid*> ();
    double tabDirections [2] = {1, -1};
    for (int i = 0; i < 10; ++i) {
        int x = rand() % screenWidth;
        int y = rand() % screenHeight;
        int size = rand() % 50 + 20;
        asteroidList.push_back(new Asteroid(x, y,size, tabDirections[rand() % 2] * (rand() % 15 + 2),tabDirections[rand() % 2] * (rand() % 10 + 2)));
    }
}

// useful functions
void checkCollision(vector<Asteroid *> A, vector<Missile *> B) {
    //for each element, if one asteroid collide with a missile, destroy both elements, else update both
for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            double distance = sqrt(pow(A[i]->GetX() - B[j]->GetX(), 2) + pow(A[i]->GetY() - B[j]->GetY(), 2));
            if (distance <= A[i]->GetSize() + B[j]->GetSize()) {
                //destroy both elements
                A.erase(A.begin() + i);
                B.erase(B.begin() + j);
            }
        }
    }
}

//function to transform deg in rad
double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

//function to transform rad in deg
double rad2deg(double radians) {
    return radians * 180.0 / M_PI;
}

//optional methods
bool Model::getDebug() {
    return this->debug;
}

void Model::SetDebug(bool b) {
    this->debug = b;
}

void Model::setIsRunning(bool running) {
    this->isRunning = running;
}

// methods
void Model::accelerate() {
     spaceship->SetXSpeed(spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())) * 1.35);
     cout << spaceship->GetYSpeed() << endl;
     spaceship->SetYSpeed(spaceship->GetYSpeed() - cos(deg2rad(spaceship->GetAngle())) * 1.35);
    cout << spaceship->GetYSpeed() << endl;
}

void Model::decelerate() {
    spaceship->SetXSpeed(spaceship->GetXSpeed() - cos(deg2rad(spaceship->GetAngle())) * 0.65);
    spaceship->SetYSpeed(spaceship->GetYSpeed() - sin(deg2rad(spaceship->GetAngle())) * 0.65);

}

void Model::rotate(int angle) {
    spaceship->SetAngle(spaceship->GetAngle() + angle );
}

void Model::shoot() {
    missileList.push_back(new Missile(spaceship->GetX(), spaceship->GetY(), 10,
                                      1.1 * (spaceship->GetXSpeed() + cos(deg2rad(spaceship->GetAngle()))),
                                      1.1 * (spaceship->GetYSpeed() + sin(deg2rad(spaceship->GetAngle())))));
}

void Model::update() {
    //check for.llisions in both lists
    checkCollision(this->asteroidList, this->missileList);
     //update the positions of all the elements
//    spaceship->SetXSpeed(50);
//    framework->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle()+90, 0, false);
    for (int i = 0; i < asteroidList.size(); ++i) {
        asteroidList[i]->Move(screenWidth, screenHeight);
        spaceship->Move(screenWidth, screenHeight);
        framework->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle()+90, 0, false);
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
