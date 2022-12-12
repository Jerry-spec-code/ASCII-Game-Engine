#ifndef FLY_H
#define FLY_H
#include "rectangle.h"
using namespace std;

class Fly : public Rectangle {
public: 
    Fly();
    Fly(char c, int length, int width, int x, int y, int height = 1);
    ~Fly();
};

#endif 
