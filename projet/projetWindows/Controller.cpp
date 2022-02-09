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
//    while (isRunning==0 && !quitPressed) {
//        //get user input
//        const Uint8* keyStates = SDL_GetKeyboardState(NULL);
//        int input = framework->GetInput();
        //input treatment for the spaceship controls

// input treatment for the spaceship controls
//        if (keyStates[SDL_SCANCODE_UP]) {
//            model->getSpaceship()->accelerate();
//        }
//
//        if (keyStates[SDL_SCANCODE_DOWN]) {
//            model->getSpaceship()->decelerate();
//        }
//
//        if (keyStates[SDL_SCANCODE_LEFT]) {
//            model->getSpaceship()->rotate(-15);
//        }
//
//        if (keyStates[SDL_SCANCODE_RIGHT]) {
//            model->getSpaceship()->rotate(15);
//        }
//        if (keyStates[SDL_SCANCODE_SPACE]) {
//            model->shoot();
//        }
//        if (keyStates[SDL_SCANCODE_ESCAPE]) {
//            quitPressed = true;
//        }
//        isRunning = model->update();
//        view->update(model->getAllFlyingObjects());
//    }

//    while the game is running
    while (isRunning==0 && !quitPressed) {
        //get user input
        int input = framework->GetInput();
            //input treatment for the spaceship controls
            switch (input) {
                case SDLK_UP:
                    model->getSpaceship()->accelerate();
                    break;
                case SDLK_DOWN:
                    model->getSpaceship()->decelerate();
                    break;
                case SDLK_LEFT:
                    model->getSpaceship()->rotate(-15);
                    break;
                case SDLK_RIGHT:
                    model->getSpaceship()->rotate(15);
                    break;
                case SDLK_SPACE:
                    model->shoot();
                    break;
                case SDLK_ESCAPE:
                    quitPressed = true;
                    break;
                default:
                    break;
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
