//
// Created by Sharper8 on 06/10/2023.
//

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

#ifndef SDLTEST_MODEL_H
#define SDLTEST_MODEL_H
//empty class model
class Model {
    // private section
    private:
    // attributes
    bool debug;
    bool isRunning;
    int screenWidth;
    int screenHeight;
    Framework *framework;
    Spaceship* spaceship;
    vector<Missile *> missileList;
    vector<Asteroid *> asteroidList;

    // public section
public:
    // constructor
    Model(int screenWidth,int screenHeight,int shipSize,int missileSize, Framework *framework);
    // destructor
    ~Model();

    //optional methods
    bool getDebug();
    void SetDebug(bool b);

    void setIsRunning(bool running);

    // methods
    void accelerate();

    void update();

    std::vector<FlyingObject*> getAllFlyingObjects();

    void decelerate();

    void rotate(int angle);

    void shoot();
};

#endif //SDLTEST_MODEL_H
