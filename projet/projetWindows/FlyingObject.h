//
// Created by Sharper8 on 18/09/2023.
//
#include <string>
using namespace std;

#ifndef SDLTEST_FLYINGOBJECT_H
#define SDLTEST_FLYINGOBJECT_H

double deg2rad(double d);

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
    //constructor
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed,double angle);

    //destructor
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
    void SetAngle(double d);

    virtual void Move();

    virtual void Move(double screenWidth, double screenHeight);

    double GetSize();

    virtual string GetTypeName()=0;

    static bool Collide(FlyingObject *o1, FlyingObject *o2);


};
#endif //SDLTEST_FLYINGOBJECT_H
