#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "gameObject.h"
#include <vector>

#include <iostream>
using namespace std;

class Border;

class Rectangle: public GameObject {
    int length;
    int width;
    char c;
public:
    Rectangle();
    Rectangle(char c, int length, int width, int x, int y, int height = 1);
    ~Rectangle();
    int getLength();
    void setLength(int length);
    int getWidth();
    void setWidth(int width);
    char getCharacter();
    void setCharacter(char c);
    void rotate() override;
    void move(Action action) override;
    void move(Direction direction) override;
    bool hitBorder(shared_ptr<Border> border) override;
};

#endif
