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
    double missileSize;
    int screenWidth;
    int screenHeight;
    Framework *framework;

    // public section
public:
    // constructor
    Model(int screenWidth,int screenHeight,int shipSize,int missileSize, Framework *framework);
    // destructor
    ~Model();

    // methods
    void accelerate();

    int update();

    std::vector<FlyingObject*> getAllFlyingObjects();

    void decelerate();

    void rotate(int angle);

    void shoot();

    //todo remettre en priové
    Spaceship* spaceship;
    vector<Missile *> missileList;
    vector<Asteroid *> asteroidList;
};

#endif //SDLTEST_MODEL_H
