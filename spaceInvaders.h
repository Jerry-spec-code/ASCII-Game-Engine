#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "game.h"
#include "action.h"
#include <memory>

using namespace std;

class SpaceInvadersDisplay;
class GameObject;
class Border;

class SpaceInvaders : public Game {
    shared_ptr<GameObject> rocket;
    shared_ptr<SpaceInvadersDisplay> spaceInvadersDisplay;
    shared_ptr<Border> border;
    int status = 1;
    int updateInterval = 75000;
public:
    SpaceInvaders();
    ~SpaceInvaders();
    void position() override;
    void go() override;
private:
    void display();
    void moveOrShoot(Action action);
    void updateView();
    void positionRocketShip();
    void spawnAliens();
    void moveAliens();
};

#endif
