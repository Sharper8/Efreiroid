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
        // input treatment for the spaceship controls for ZSQD+enter
        if (keyStates[SDL_SCANCODE_UP] || keyStates[SDL_SCANCODE_W]) {
            model->getSpaceship()->accelerate();
        }

        if (keyStates[SDL_SCANCODE_DOWN] || keyStates[SDL_SCANCODE_S]) {
            model->getSpaceship()->decelerate();
        }

        if (keyStates[SDL_SCANCODE_LEFT] || keyStates[SDL_SCANCODE_A]) {
            model->getSpaceship()->rotate(-5);
        }

        if (keyStates[SDL_SCANCODE_RIGHT] || keyStates[SDL_SCANCODE_D]) {
            model->getSpaceship()->rotate(5);
        }
        if (input == SDLK_SPACE || input == SDLK_RETURN) {
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
