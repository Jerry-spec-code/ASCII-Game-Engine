#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "game.h"
#include <memory>

using namespace std;

class SpaceInvadersDisplay;
class GameObject;

class SpaceInvaders : public Game {
    shared_ptr<GameObject> rocket;
    shared_ptr<SpaceInvadersDisplay> spaceInvadersDisplay;
    int status = 1;
    int updateInterval = 75000;
public:
    SpaceInvaders();
    ~SpaceInvaders();
    void position() override;
    void go() override;
private:
    void display();
};

#endif
