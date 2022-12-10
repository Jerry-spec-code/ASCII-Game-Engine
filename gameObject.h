#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
using namespace std;

class GameObject {
    int height;
    int x;
    int y;
public:
    GameObject();    
    GameObject(int x, int y, int height);
    ~GameObject();
    int getHeight();
    int getXPos();
    int getYPos();
    void setHeight(int height);
    void setXPos(int x);
    void setYPos(int y);
    void setPos(int x, int y);
    void setPos(int x, int y, int height);
    virtual void getData();
};

#endif
