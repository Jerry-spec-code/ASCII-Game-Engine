#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "gameobject.h"

#include <iostream>
using namespace std;

class Rectangle: public GameObject {
    int length;
public:
    Rectangle();
    ~Rectangle();
};

#endif