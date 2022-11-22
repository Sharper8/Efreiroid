#include "FlyingObject.h"
#include "Asteroid.h"
#include "Missile.h"
#include "Spaceship.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int main(int argc, char* argv[]) {
    //MVC implementation
    Controller controller(60, 40, 10);
    controller.LaunchGame();
    return 0;
}