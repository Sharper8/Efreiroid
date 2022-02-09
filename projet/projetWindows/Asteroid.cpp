//
// Created by Sharper8 on 07/09/2023.
//
#include "Asteroid.h"
#include "FlyingObject.h"
#include <cmath>
#include <vector>
#include <random>


Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle): FlyingObject(x, y, size, xSpeed, ySpeed,angle){
    nbExplosionsLeft = (int)size/100;
}

string Asteroid::GetTypeName() {
    return "Asteroid";
}

void Asteroid::Move(double screenWidth, double screenHeight) {
    this->SetX(this->GetX() + this->GetXSpeed());
    this->SetY(this->GetY() + this->GetYSpeed());
    if (x > screenWidth) {
        x=0;
    }
    if (x < 0) {
        x=screenWidth;
    }
    if (y > screenHeight) {
        y=0;
    }
    if (y < 0) {
        y=screenHeight;
    }
}

int Asteroid::getNbExplosionsLeft() const {
    return nbExplosionsLeft;
}

Asteroid* Asteroid::Explode(double xSpeed, double ySpeed) {
    size = size / 2;
    nbExplosionsLeft--;
    //change the speed of the new asteroids to be the same as the old one but with an impact of the missile
    this->xSpeed = 10*xSpeed/size;
    this->ySpeed = 10*ySpeed/size;
    //randomness initialization
    std::random_device rd;
    std::default_random_engine generator(rd());
    //generate random xSpeed and ySpeed
    std::uniform_real_distribution<double> xDistribution(-5, 5);
    std::uniform_real_distribution<double> yDistribution(-5, 5);
    double asteroidxSpeed = xDistribution(generator) + this->xSpeed / size;
    double newAsteroidySpeed = yDistribution(generator)+this->ySpeed/size;
    auto *newAsteroid = new Asteroid(x, y, size, asteroidxSpeed, newAsteroidySpeed, angle);
    //add it to the list
    return newAsteroid;
}

Asteroid *Asteroid::randomAsteroid(int screenWidth, int screenHeight) {
    Asteroid *newAsteroid;
    // create a vector of vector that stores the coordinates of 9 even zones on the screen, exclude the middle of the screen
    vector<vector<int>> zones = {{screenWidth / 3, 0, 0, screenHeight / 3},
                                 {screenWidth / 3, 0, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth / 3, 0, screenHeight * 2 / 3, screenHeight},
                                 {screenWidth * 2 / 3, screenWidth, 0, screenHeight / 3},
                                 {screenWidth * 2 / 3, screenWidth, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth * 2 / 3, screenWidth, screenHeight * 2 / 3, screenHeight},
                                 {screenWidth, screenWidth * 2 / 3, 0, screenHeight / 3},
                                 {screenWidth, screenWidth * 2 / 3, screenHeight / 3, screenHeight * 2 / 3},
                                 {screenWidth, screenWidth * 2 / 3, screenHeight * 2 / 3, screenHeight}};
    // Use std::random_device to seed the engine
    std::random_device rd;
    std::default_random_engine generator(rd());
    // Create a uniform_int_distribution for choosing a random zone
    std::uniform_int_distribution<int> distribution(0, (int)zones.size() - 1);
    // choose a random zone from the vector of zones with uniform_int_distribution() function
    int randomZoneIndex = distribution(generator);
    std::vector<int> selectedZone = zones[randomZoneIndex];
    //choose a random set of coordinates base on the zones coordinates of the chosen zone using uniform_real_distribution () function
    std::uniform_real_distribution<double> xDistribution(selectedZone[1], selectedZone[0]);
    std::uniform_real_distribution<double> yDistribution(selectedZone[2], selectedZone[3]);
    //generate a random angle between-180 and 180° using uniform_int_distribution
    double angle = distribution(generator) * 40 - 180;
    //generate a random double between 55 and 155 for size
    std::uniform_real_distribution<double> sizeDistribution(55, 250);
    double size = sizeDistribution(generator);
    // Generate random x and y coordinates
    double X = xDistribution(generator);
    double Y = yDistribution(generator);
    double XSpeed = cos(deg2rad(angle))*5;
    double YSpeed = sin(deg2rad(angle))*5;
    //create a new asteroid
    newAsteroid = new Asteroid(X, Y, size, XSpeed, YSpeed,angle);
    return newAsteroid;
}
