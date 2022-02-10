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
    [[nodiscard]] double GetX() const;
    [[nodiscard]] double GetY() const;
    [[nodiscard]] double GetXSpeed() const;
    [[nodiscard]] double GetYSpeed() const;
    [[nodiscard]] double GetAngle() const;

    //setters
    void SetX(double d);
    void SetY(double d);


    virtual void Move(double screenWidth, double screenHeight);
    [[nodiscard]] double GetSize() const;
    virtual string GetTypeName()=0;
    static bool Collide(FlyingObject *o1, FlyingObject *o2);


};
#endif //SDLTEST_FLYINGOBJECT_H
