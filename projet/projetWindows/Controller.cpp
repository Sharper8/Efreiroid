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


// methods§
bool Controller::getIsRunning() {
    return this->isRunning;
}

void Controller::setIsRunning(bool running) {
    this->isRunning = running;
}

void Controller::LaunchGame() {
    while (isRunning) {
        //get user input
        int input = framework->GetInput();
        //input treatment passed to the model
        if (input == SDLK_ESCAPE) {
//            cout << "Game over" << endl;
            model->setIsRunning(false);
            setIsRunning(false);
            //delete the canvas
            delete framework;
        }
        if (input == SDLK_UP) {
            // Accelerate
            model->accelerate();
        }
        if (input == SDLK_DOWN) {
            //decelerate
            model->decelerate();
        }
        if (input == SDLK_LEFT) {
            //rotate left
            model->rotate(-20);
        }
        if (input == SDLK_RIGHT) {
            //rotate right
            model->rotate(20);
        }
        //shoot a missile
        if (input == SDLK_SPACE) {
            //shoot a missile
            model->shoot();
        }
        //settings commands
        if (input == SDLK_p) {
            model->SetDebug(!model->getDebug());
        }
        model->update();
        view->update(model->getAllFlyingObjects());
    }


}
