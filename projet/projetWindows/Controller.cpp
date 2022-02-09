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
                    model->rotate(-15);
                    break;
                case SDLK_RIGHT:
                    model->rotate(15);
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
        cout<<"Congrats, You won."<<isRunning<<endl;
    }
    else{
        cout<<"Too bad ! You lost."<<isRunning<<endl;
    }
}
