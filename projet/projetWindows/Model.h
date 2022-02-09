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
    Spaceship *spaceship;
    vector<Missile *> missileList;
    vector<Asteroid *> asteroidList;

public:
    // constructor
    Model(int screenWidth, int screenHeight, int shipSize, int missileSize, Framework *framework);

    // destructor
    ~Model();

    Spaceship* getSpaceship();

    void shoot();

    int update();

    std::vector<FlyingObject *> getAllFlyingObjects();

};
#endif //SDLTEST_MODEL_H
