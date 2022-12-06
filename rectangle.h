#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
using namespace std;

class GameObject {
    int height;
    int xPos;
    int yPos;
public:
    GameObject() {}
    ~GameObject() {}
    int getHeight();
    int getXPos();
    int getYPos();
};

#endif
