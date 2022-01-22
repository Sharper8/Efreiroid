#include <iostream>
#include "FlyingObject.h"
#include "Asteroid.h"
#include "Missile.h"
#include "Spaceship.h"
#include <cstdlib>
#include <vector>
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int WinMain(int argc, char* argv[]) {
    //debug value
    bool DEBUG = true;
    //initialisation of the random function
    srand(static_cast<unsigned>(time(NULL)));

    //MVC implementation
    Controller controller(60, 50, 10);
    controller.LaunchGame();
    return 0;
}