//
// Created by Sharper8 on 18/09/2023.
//
#include <string>
using namespace std;

#ifndef SDLTEST_FLYINGOBJECT_H
#define SDLTEST_FLYINGOBJECT_H

//define flying object class
class FlyingObject {

    protected:
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;
    double angle;

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
    double GetAngle();

    //setters
    void SetX(double xSpeed);
    void SetY(double ySpeed);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetSize(double size);
    void SetAngle(double angle);

    virtual void Move();

    virtual void Move(double screenWidth, double screenHeight);

    double GetSize();

    virtual string GetTypeName()=0;

    static bool Collide(FlyingObject *o1, FlyingObject *o2);


};
#endif //SDLTEST_FLYINGOBJECT_H
