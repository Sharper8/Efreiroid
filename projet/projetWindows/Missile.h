//
// Created by Sharper8 on 11/09/2023.
//

#ifndef SDLTEST_MISSILE_H
#define SDLTEST_MISSILE_H


class Missile {

    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;

    public:

    //destructeur
    ~Missile();

    //getters
    double GetX();
    double GetY();
    double GetXSpeed();
    double GetYSpeed();

    //setters
    void SetX(double xSpeed);
    void SetY(double ySpeed);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetSize(double size);

    void Move();

    void Move(double screenWidth, double screenHeight);

    double GetSize();

    Missile(double x, double y, double size, double xSpeed, double ySpeed);
};
#endif //SDLTEST_MISSILE_H
