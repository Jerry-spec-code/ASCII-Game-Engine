#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "action.h"
#include "direction.h"

#include <iostream>
using namespace std;

class GameObject {
    int height;
    int x;
    int y;
public:
    GameObject();    
    GameObject(int x, int y, int height = 1);
    virtual ~GameObject();
    int getHeight();
    int getXPos();
    int getYPos();
    void setHeight(int height = 1);
    void setXPos(int x);
    void setYPos(int y);
    void setPos(int x, int y);
    void setPos(int x, int y, int height = 1);
    virtual void rotate();
    virtual void move(Action action);
    virtual void move(Direction direction);
};

#endif
