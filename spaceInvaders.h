#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "game.h"

class SpaceInvaders : public Game {
    int status = 1;
public:
    SpaceInvaders();
    ~SpaceInvaders();
    void position() override;
    void go() override;
};

#endif
