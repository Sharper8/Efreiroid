//
// Created by Sharper8 on 06/10/2023.
//

                        ////////////////////////////////////////
                        // Description of the class objective //
                        ////////////////////////////////////////
// The controller class launches the game and manages the user input. It is the link between the model and the view.

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
    int isRunning;

    public:
    Controller(int fps,int shipSize,int missileSize);
    ~Controller();
    void LaunchGame();
};
#endif //SDLTEST_CONTROLLER_H
