//
// Created by Sharper8 on 06/10/2023.
//

#include "Controller.h"


#define NB_ASTEROIDS 10
#define DEBUG True

// constructor
Controller::Controller(int fps, int shipSize, int missileSize) {
    this->framework = new Framework(fps, shipSize, missileSize);
    this->model = new Model(framework->GetScreenWidth(), framework->GetScreenHeight(), 50, 10);
    this->view = new View();
    this->isRunning = true;
}

// methods
//isrunning
bool Controller::getIsRunning() {
    return this->isRunning;
}

void Controller::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}

void Controller::LaunchGame() {
    while (this->isRunning) {
        //get user input
        int input = this->framework->GetInput();
        //input treatment passed to the model
        if (input == SDLK_ESCAPE) {
            model->setIsRunning(false);
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
        view->update(model->getSpaceAllFlyingobjects());
    }

}
