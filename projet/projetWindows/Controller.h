//
// Created by Sharper8 on 06/10/2023.
//
#include "Model.h"
#include "View.h"
#include "framework.hpp"


#ifndef SDLTEST_CONTROLLER_H
#define SDLTEST_CONTROLLER_H
// define the class Controller
class Controller {

    // private section
    private:
    // attributes
    Model* model;
    Framework* framework;
    View* view;
    bool isRunning;
    // public section
    public:
    // constructor
    Controller(int fps,int shipSize,int missileSize);
    // destructor
    ~Controller();
    // methods
    bool getIsRunning();
    void setIsRunning(bool running);
    void LaunchGame();
};
#endif //SDLTEST_CONTROLLER_H
