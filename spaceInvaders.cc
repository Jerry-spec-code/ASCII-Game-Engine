#include "spaceInvaders.h"
#include <ncurses.h>
#include "keyboard.h"
#include "spaceInvadersDisplay.h"
#include "action.h"
#include "direction.h"
#include "border.h"
#include "bullet.h"
#include "rocketShip.h"
#include "bullet.h"
#include "spaceAlien.h"
#include <unistd.h>
#include <time.h>

#include <string>
#include <chrono>
#include <thread>

#include <iostream>
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;

SpaceInvaders::SpaceInvaders(): spaceInvadersDisplay{make_shared<SpaceInvadersDisplay>()}, 
rocket{make_shared<RocketShip>()}, border{make_shared<Border>()} {}

SpaceInvaders::~SpaceInvaders() {}

void SpaceInvaders::position() {
    srand (time(NULL));
    positionRocketShip();
    spawnAliens();
    moveAliens();
}

void SpaceInvaders::go() {
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    input->setInputTime(2000);
    input->setKey('r', Action::CW);
    wtimeout(stdscr, input->getInputTime());
    while (status != 0) {
        spaceInvadersDisplay->inProgress();
        display();
        clock_t t = clock();
        Action action = Action::NONE;
        while (clock() - t < updateInterval) {
            noecho();
            action = input->getAction();	
            moveOrShoot(action);
            if (status == 0) {
                break;
            }
            display();	
            if (action == Action::NONE) {
                updateView();
                break;
            }
        }
        updateView();
    }
    display();
    sleep_for(5s);
    endwin();
}

void SpaceInvaders::display() {
    spaceInvadersDisplay->updateObjects(getObjects());
    spaceInvadersDisplay->render();
}

void SpaceInvaders::moveOrShoot(Action action) {
    if (dynamic_cast<RocketShip *>(rocket.get())) {
        RocketShip *ship = static_cast<RocketShip *>(rocket.get());
        if (action == Action::UP) {
            spawnBullet(ship->getDirection());
        }
        else if (action == Action::CW) {
            ship->rotate();
        }
        else {
            ship->move(action);
            if (ship->hitBorder(border)) {
                spaceInvadersDisplay->hitBorder(aliensKilled);
                status = 0;
            } 
        }
    }
}

void SpaceInvaders::updateView() {
    spawnAliens();
    moveAliens();
}

void SpaceInvaders::positionRocketShip() {
    if (dynamic_cast<RocketShip *>(rocket.get())) {
        rocket->setXPos(border->getBorderLength() / 2);
        rocket->setYPos(border->getBorderHeight() / 2);
        int xCor = rocket->getXPos();
        int yCor = rocket->getYPos();
        RocketShip *ship = static_cast<RocketShip *>(rocket.get());
        ship->push_back(make_tuple(xCor, yCor, 'O'));
        ship->push_back(make_tuple(xCor - 1, yCor, 'O'));
        ship->push_back(make_tuple(xCor - 2, yCor, 'O'));
        ship->push_back(make_tuple(xCor, yCor + 1, 'O'));
        ship->push_back(make_tuple(xCor, yCor - 1, 'O'));
        ship->setDirection(Direction::WEST);
        addGameObject(rocket);
    }
}

void SpaceInvaders::spawnBullet(Direction direction) {
    shared_ptr<Bullet> bullet = make_shared<Bullet>('-', rocket->getXPos() + 3, rocket->getYPos());
    if (direction == Direction::EAST) {
        bullet = make_shared<Bullet>('-', rocket->getXPos() + 3, rocket->getYPos());
    }
    else if (direction == Direction::WEST) {
        bullet = make_shared<Bullet>('-', rocket->getXPos() - 3, rocket->getYPos());
    }
    else if (direction == Direction::SOUTH) {
        bullet = make_shared<Bullet>('|', rocket->getXPos(), rocket->getYPos() + 3);
    }
    else if (direction == Direction::NORTH) {
        bullet = make_shared<Bullet>('|', rocket->getXPos(), rocket->getYPos() - 3);
    }
    addGameObject(bullet);
    while (!hasAlien(bullet->getXPos(), bullet->getYPos()) && 
        !border->onBorder(bullet->getYPos(), bullet->getXPos())) {
        display();
        bullet->move(direction);
    }
    if (hasAlien(bullet->getXPos(), bullet->getYPos())) {
        removeAlien(bullet->getXPos(), bullet->getYPos());
        aliensKilled++;
    }
    removeGameObject(bullet);
}

void SpaceInvaders::spawnAliens() {
    for (int i = offset; i < border->getBorderHeight() - offset; i++) {
        if (!border->isBorderRow(i, 0)) {
            shared_ptr<GameObject> alien = make_shared<Alien>('X', 0, i);
            addGameObject(alien);
        }
        if (!border->isBorderRow(i, border->getBorderLength())) {
            shared_ptr<GameObject> alien = make_shared<Alien>('X', border->getBorderLength() - 1, i);
            addGameObject(alien);
        }
    } 

}

void SpaceInvaders::moveAliens() {
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Alien *>(objects[i].get())) {
            if (objects[i]->getXPos() < rocket->getXPos()) {
                objects[i]->setXPos(objects[i]->getXPos() + 1);
            }
            else {
                objects[i]->setXPos(objects[i]->getXPos() - 1);
            }
        }
    }
}

bool SpaceInvaders::hasAlien(int x, int y) {
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Alien *>(objects[i].get())) {
            if (objects[i]->getXPos() == x && objects[i]->getYPos() == y) {
                return true;
            }
        }
    }
    return false;
}

void SpaceInvaders::removeAlien(int x, int y) {
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Alien *>(objects[i].get())) {
            if (objects[i]->getXPos() == x && objects[i]->getYPos() == y) {
                removeGameObject(objects[i]);
            }
        }
    }
}
