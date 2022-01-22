//
// Created by Sharper8 on 06/10/2023.
//

#include "Controller.h"


#define NB_ASTEROIDS 10
#define DEBUG True

// constructor
Controller::Controller(int fps, int shipSize, int missileSize) {
    this->framework = new Framework(fps, shipSize, missileSize);
    this->model = new Model(framework->GetScreenWidth(), framework->GetScreenHeight(), shipSize, missileSize, framework);
    this->view = new View(framework);
    this->isRunning = true;
}

//destructor
Controller::~Controller() {
    delete model;
    delete view;
}

//function to transform deg in rad
double degvrad(double degrees) {
    return degrees * M_PI / 180.0;
}

void Controller::setIsRunning(bool running) {
    this->isRunning = running;
}

void Controller::LaunchGame() {
    while (isRunning) {
        //get user input
        int input = framework->GetInput();
        //input treatment for the spaceship controls
        switch (input) {
            case SDLK_UP:
                model->accelerate();
                break;
            case SDLK_DOWN:
                model->decelerate();
                break;
            case SDLK_LEFT:
                model->rotate(-10);
                break;
            case SDLK_RIGHT:
                model->rotate(10);
                break;
            case SDLK_SPACE:
                model->shoot();
                break;
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            default:
                break;

        }
        model->update();
        view->update(model->getAllFlyingObjects());
    }
    delete framework;
    delete model;
    delete view;
}
