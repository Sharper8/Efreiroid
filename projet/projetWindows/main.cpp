#include <iostream>
#include "framework.hpp"
#include "Asteroid.h"
#include "Missile.h"
#include "Spaceship.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#define NB_ASTEROIDS 5
using namespace std;

bool checkCollision(Asteroid* A, Missile* B) {
    double distance = sqrt(pow(A->GetX() - B->GetX(), 2) + pow(A->GetY() - B->GetY(), 2));
    if (distance <= A->GetSize() + B->GetSize()) {
        return true;
    }
    return false;
}
//function to transform deg in rad
double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

//function to transform rad in deg
double rad2deg(double radians) {
    return radians * 180.0 / M_PI;
}

int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{
    //initialisation of the random function
    srand(static_cast<unsigned>(time(NULL)));
    //framework initialisation
    Framework framework(60, 20, 10);
    //debug value
    bool DEBUG = true;
    //init a list of asteroids with random speed, size and position
    vector<Missile*> missileList;
    //vector for missiles
    vector<Asteroid*> asteroidList;
    //init a list of missiles with random speed, size and position

    for (int i = 0; i < NB_ASTEROIDS; ++i) {
        double tabDirections [2] = {1, -1};
        asteroidList.push_back(new Asteroid(rand() % framework.GetScreenWidth(), rand() % framework.GetScreenHeight(), rand() % 50 + 20, tabDirections[rand() % 2] * (rand() % 15 + 2), tabDirections[rand() % 2] * (rand() % 10 + 2)));
    }
    Spaceship spaceship(framework.GetScreenWidth()/2,framework.GetScreenHeight()/2,0, 10 , 0, 0);
    framework.DrawShip(spaceship.GetX(), spaceship.GetY(), 0,0,false);
    //for asteroind in vector DEBUG
//    for (int i = 0; i < asteroidList.size(); ++i) {
//        //print its parameters
//        cout << "Asteroid " << i << " speed: " << asteroidList[i]->GetXSpeed() << " " << asteroidList[i]->GetYSpeed() << endl;
//    }
    //main loop
    while(true)
    {
        //get user input
        int input = framework.GetInput();
        //input treatment
        if(input == SDLK_ESCAPE)
        {
            break;
        }
        //MVC
        //move the spaceship has in space
        if(input == SDLK_UP)
        {
            //accelerate the spaceship with the forward thrust
            spaceship.SetXSpeed(spaceship.GetXSpeed() + cos(deg2rad(spaceship.GetAngle())) * 1.35);
            spaceship.SetYSpeed(spaceship.GetYSpeed() + sin(deg2rad(spaceship.GetAngle())) * 1.35);
        }
        if(input == SDLK_DOWN)
        {
            //decelerate the spaceship with angular friction
            spaceship.SetXSpeed(spaceship.GetXSpeed() - cos(deg2rad(spaceship.GetAngle())) * 0.65);
            spaceship.SetYSpeed(spaceship.GetYSpeed() - sin(deg2rad(spaceship.GetAngle())) * 0.65);
        }
        if(input == SDLK_LEFT)
        {
            spaceship.SetAngle(spaceship.GetAngle() - 20 );
        }
        if(input == SDLK_RIGHT)
        {
            spaceship.SetAngle(spaceship.GetAngle() + 20);
        }
        //shoot a missile
        if(input == SDLK_SPACE)
        {
            //create a missile with the spaceship position and speed
            missileList.push_back(new Missile(spaceship.GetX(), spaceship.GetY(), 10, 1.1*(spaceship.GetXSpeed() + cos(deg2rad(spaceship.GetAngle()))), 1.1*(spaceship.GetYSpeed() + sin(deg2rad(spaceship.GetAngle())))));
        }
        //settings commands
        if(input == SDLK_p)
        {
            DEBUG = !DEBUG;
        }
        //check for collisions PROBLEME on peut tirer sans asteroids et asteroid sans tirer, comment faire la boucle
        for (int i = 0; i < asteroidList.size(); ++i) {
            for (int j = 0; j < missileList.size(); ++j) {
                if (checkCollision(asteroidList[i], missileList[j])) {
                    //destroy both elements
                    asteroidList[i]->~Asteroid();
                    missileList[j]->~Missile();
                    //remove them from the vector
                    asteroidList.erase(asteroidList.begin() + i);
                    missileList.erase(missileList.begin() + j);
                    //free memory
                    delete asteroidList[i];
                    delete missileList[j];

                    //DEBUG
                    cout << "Collision" << endl;
                }
                else{
                    //DEBUG
//                    cout << "No collision" << endl;
                    missileList[j]->Move(framework.GetScreenWidth(), framework.GetScreenHeight());
                    //show asteroid and missile on the canvas
                    framework.DrawMissile(missileList[j]->GetX(), missileList[j]->GetY());
                }
            }
            asteroidList[i]->Move(framework.GetScreenWidth(), framework.GetScreenHeight());
            framework.DrawAsteroid(asteroidList[i]->GetX(), asteroidList[i]->GetY(), asteroidList[i]->GetSize());
        }
        framework.DrawShip(spaceship.GetX(), spaceship.GetY(), spaceship.GetAngle()+90, 0, false);
        spaceship.Move(framework.GetScreenWidth(), framework.GetScreenHeight());
        framework.Update();

    }

    //free memory
    for (int i = 0; i < asteroidList.size(); ++i) {
        delete asteroidList[i];
    }
     return 0;
}