#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "gameobject.h"

#include <iostream>
using namespace std;

class Rectangle: public GameObject {
    int length;
    int width;
    vector<shared_ptr<tuple<int, int, char>>> rectangle;
public:
    Rectangle();
    ~Rectangle();
};

#endif
