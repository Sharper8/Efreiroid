//
// Created by Sharper8 on 06/10/2023.
//

#include "Controller.h"
// constructor
Controller::Controller(int fps, int shipSize, int missileSize) {
    this->framework = new Framework(fps, shipSize, missileSize);
    this->model = new Model(framework->GetScreenWidth(), framework->GetScreenHeight(), shipSize, missileSize, framework);
    this->view = new View(framework);
    this->isRunning = 0;
}

//destructor
Controller::~Controller() {//delete all the elements of the lists
   //delete the spaceship
    delete model;
    delete framework;
    delete view;
}

void Controller::LaunchGame() {
    int quitPressed=0;
    while (isRunning==0 && !quitPressed) {
        //get user input
        const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
        int input = framework->GetInput();
        // input treatment for the spaceship controls
        if (keyStates[SDL_SCANCODE_UP]) {
            model->getSpaceship()->accelerate();
        }

        if (keyStates[SDL_SCANCODE_DOWN]) {
            model->getSpaceship()->decelerate();
        }

        if (keyStates[SDL_SCANCODE_LEFT]) {
            model->getSpaceship()->rotate(-5);
        }

        if (keyStates[SDL_SCANCODE_RIGHT]) {
            model->getSpaceship()->rotate(5);
        }
        if (input == SDLK_SPACE) {
            model->shoot();
        }
        if (keyStates[SDL_SCANCODE_ESCAPE]) {
            quitPressed = true;
        }
        isRunning = model->update();
        view->update(model->getAllFlyingObjects());
    }
    if (isRunning == 1){
        cout<<"Congrats, You won."<<endl;
    }
    else{
        cout<<"Too bad ! You lost."<<endl;
    }
}
