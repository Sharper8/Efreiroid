//
// Created by Sharper8 on 06/10/2023.
//
#include "FlyingObject.h"
#include "framework.hpp"
#include <vector>

using namespace std;

#ifndef SDLTEST_VIEW_H
#define SDLTEST_VIEW_H


class View {
    //attributes
    Framework* framework;
public :
    //constructors
    View(Framework *framework);
    void update(vector<FlyingObject*> flyingObjectsList);
};
#endif //SDLTEST_VIEW_H