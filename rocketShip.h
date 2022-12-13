#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "bitmap.h"
#include "direction.h"
#include "action.h"

class RocketShip : public Bitmap {
    Direction direction;
    int xCor, yCor; //COR stands for Center of Rotation.
public:
    RocketShip();
    RocketShip(std::initializer_list<tuple<int, int, char>> init);
    ~RocketShip();
    Direction getDirection();
    void setDirection(Direction direction);
    void rotate();
    void move(Action action);
};

#endif
