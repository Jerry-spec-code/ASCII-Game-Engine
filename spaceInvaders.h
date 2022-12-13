#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "game.h"
#include "action.h"
#include "direction.h"
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
    int aliensKilled = 0;
    int offset = 2;
    int updateInterval = 1500000;
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
    void spawnBullet(Direction direction);
    bool hasAlien(int x, int y);
    void removeAlien(int x, int y);
    bool hitAlien();
};

#endif
