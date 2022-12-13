#include "iceCreamDrop.h"
#include <ncurses.h>
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"
#include "gameObject.h"
#include "border.h"
#include <vector>
#include <memory>
#include <stdlib.h>    
#include <time.h>
#include "keyboard.h"
#include "iceCream.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include "iceCreamDisplay.h"
#include "fly.h"
#include "collision.h"

#include <string>
#include <chrono>
#include <thread>

#include <iostream>
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;

IceCreamDrop::IceCreamDrop(): border{make_shared<Border>()}, lowerBoundHole{border->getBorderLength() / 4}, 
upperBoundHole{3 * (border->getBorderLength() / 4)}, iceCreamDisplay{make_shared<IceCreamDisplay>()} {
    iceCream = make_shared<IceCream>('O', (border->getBorderLength() - 2) / 2, firstPlatformHeight - 1, 1);
}

IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::go() {			
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    while (status != 0) {
        iceCreamDisplay->inProgress();
        displayHelper();
        clock_t t = clock();
        while (clock() - t < updateInterval) {
            noecho();
            Action action = input->getAction();	
            if (dynamic_cast<IceCream *>(iceCream.get())) {
                moveIceCream(action);
                if (status == 0) {
                    break;
                }
            }
            if (atLastPlatform()) {
                updateView();
            }
            displayHelper();	
        }
        updateView();
    }
    displayHelper();
    sleep_for(5s);
    endwin();			
}

bool IceCreamDrop::atLastPlatform() {
    return iceCream->getYPos() + 1 == getLastPlatformHeight();
}

void IceCreamDrop::position() {
    srand (time(NULL));
    positionPlatforms();
    positionIceCream();
}

void IceCreamDrop::positionIceCream() {
    addGameObject(iceCream);
}

void IceCreamDrop::positionPlatforms() {
    for (int i = firstPlatformHeight; i < border->getBorderHeight(); i += offset) {
        makeNewPlatform(i);
    }
}

int IceCreamDrop::getLastPlatformHeight() {
    int i = firstPlatformHeight;
    while (i < border->getBorderHeight()) {
        i += offset;
    }
    return i - offset; 
}

void IceCreamDrop::makeNewPlatform(int y) {
    int holeLocation = getRandomNumber(lowerBoundHole, upperBoundHole);
    int randNum = 2 * getRandomNumber(0, 1) - 1;
    addGameObject(make_shared<Rectangle>('-', holeLocation - 1, 1, 1, y));
    addGameObject(make_shared<Rectangle>('-', border->getBorderLength() - 4 - holeLocation, 1, holeLocation + 3, y));
    makeFly(holeLocation + randNum, y - 1);
}

void IceCreamDrop::makeFly(int x, int y) {
    int randNum = getRandomNumber(1, flyFrequency);
    if (randNum == 1) {
        shared_ptr<GameObject> fly = make_shared<Fly>('X', 3, 1, x, y);
        addGameObject(fly);
    }
}

void IceCreamDrop::updateView() {
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Character *>(objects[i].get()) || dynamic_cast<Rectangle *>(objects[i].get())) {
            objects[i]->setYPos(objects[i]->getYPos() - 1);
            if (iceCream->getYPos() < 1) {
                status = 0;
                break;
            }
            if(objects[i]->getYPos() < 1) {
                objects.erase(objects.begin() + i);
                i--;
            }
        }
    }
    if (makeNew) {
        makeNewPlatform(getLastPlatformHeight());
        makeNew = false;
    }
    else {
        makeNew = true;
    }
    if (iceCream->getYPos() < 1) {
        iceCreamDisplay->vanishUpdate(numOfPlatformsPassed);
        status = 0;
    }
}

int IceCreamDrop::getRandomNumber(int lower, int higher) {
    return (rand() % (higher - lower)) + lower;
}

bool IceCreamDrop::hitFly() {
    shared_ptr<Collision> collision = make_shared<Collision>();
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Fly *>(objects[i].get())) {
            if (collision->isColliding(iceCream, objects[i])) {
                return true;
            }
        }
    }
    return false;
}

void IceCreamDrop::moveIceCream(Action action) {
    bool fall = isEmpty(iceCream->getXPos(), iceCream->getYPos() + 1) && !atLastPlatform();
    IceCream *cream = static_cast<IceCream *>(iceCream.get());
    cream->updateIceCreamPosition(action, border, fall);
    if (fall) {
        numOfPlatformsPassed++;
        iceCreamDisplay->inProgress();
        displayHelper();
    }
    if (hitFly()) {
        for (int i = 0; i < 3 * offset; i++) {
            if (action == Action::RIGHT) {
                cream->updateIceCreamPosition(Action::LEFT, border, fall);
            }
            else if (action == Action::LEFT) {
                cream->updateIceCreamPosition(Action::RIGHT, border, fall);
            }
            iceCreamDisplay->hitFlyUpdate(numOfPlatformsPassed);
            displayHelper();
            sleep_for(0.05s);
        }
        status = 0;
    }
}

void IceCreamDrop::displayHelper() {
    iceCreamDisplay->updateObjects(getObjects());
    iceCreamDisplay->render();
}


