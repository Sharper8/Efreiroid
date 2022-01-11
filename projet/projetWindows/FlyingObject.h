//
// Created by Sharper8 on 18/09/2023.
//

#ifndef SDLTEST_FLYINGOBJECT_H
#define SDLTEST_FLYINGOBJECT_H

//define flying object class
class FlyingObject {

    double x;

    double y;
    double size;
    double xSpeed;
    double ySpeed;
public:

    //constructeur par défaut
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);
//    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);

    //destructeur
    ~FlyingObject();

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

};
#endif //SDLTEST_FLYINGOBJECT_H
