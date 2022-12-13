#ifndef BULLET_H
#define BULLET_H

#include <memory>
#include "character.h"
#include "direction.h"
using namespace std;

class Border;

class Bullet : public Character {
    Direction direction;
public:
    Bullet(char c, int x, int y, int height = 1);
    ~Bullet();
    void move(Direction direction) override;
    void setDirection(Direction direction);
    Direction getDirection();
    bool hitBorder(shared_ptr<Border> border) override;
};

#endif
