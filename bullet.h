#ifndef BULLET_H
#define BULLET_H

#include "character.h"
#include "direction.h"
using namespace std;

class Bullet : public Character {
    Direction direction;
public:
    Bullet(char c, int x, int y, int height = 1);
    ~Bullet();
    void move(Direction direction);
    void setDirection(Direction direction);
    Direction getDirection();
};

#endif
