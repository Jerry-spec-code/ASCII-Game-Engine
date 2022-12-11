#include "iceCreamDrop.h"
#include <ncurses.h>
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"
#include "gameObject.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include "border.h"
#include <vector>
#include <memory>
#include <stdlib.h>    
#include <time.h>
#include "keyboard.h"

IceCreamDrop::IceCreamDrop(): border{make_shared<Border>()}, lowerBoundHole{border->getBorderLength() / 4}, 
upperBoundHole{3 * (border->getBorderLength() / 4)} {
    iceCream = make_shared<Character>('O', (border->getBorderLength() - 2) / 2, firstPlatformHeight - 1, 1);
}

IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::go() {			
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    while (status != 0) {
        shared_ptr<Display> display_border = make_shared<BorderDisplay>();
        shared_ptr<Display> display_status = make_shared<StatusDisplay>(3);
        shared_ptr<Display> display_objects = make_shared<GameDisplay>(getObjects());
        display_objects->display();
        display_border->display();
        display_status->display();
        refresh();	
        for (int i = 0; i < 40; i++) {
            noecho();
            Action action = input->getAction();	
            updateIceCreamPosition(action);	
            display_objects->display();
            refresh();	
        }
        updateView();
    }
    endwin();			
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

void IceCreamDrop::makeNewPlatform(int y, bool addFly) {
    int holeLocation = getRandomNumber(lowerBoundHole, upperBoundHole);
    addGameObject(make_shared<Rectangle>(holeLocation - 1, 1, 1, y, 1, '-'));
    addGameObject(make_shared<Rectangle>(border->getBorderLength() - 4 - holeLocation, 1, holeLocation + 3, y, 1, '-'));
    if (addFly) {
        makeFly(holeLocation - 1, y - 1);
    }
}

void IceCreamDrop::makeFly(int x, int y) {
    int randNum = getRandomNumber(1, flyFrequency);
    if (randNum == 1) {
        addGameObject(make_shared<Rectangle>(3, 1, x, y, 1, 'X'));
    }
}

void IceCreamDrop::updateIceCreamPosition(Action action) {
    if(action == Action::RIGHT) {
        iceCream->setXPos(iceCream->getXPos() + 1);
        if(border->onBorder(iceCream->getYPos(), iceCream->getXPos())) {
            iceCream->setXPos(1);
        }
    }
    else if (action == Action::LEFT) {
        iceCream->setXPos(iceCream->getXPos() - 1);
        if(border->onBorder(iceCream->getYPos(), iceCream->getXPos())) {
            iceCream->setXPos(border->getBorderLength() - 2);
        }
    }
    if (isEmpty(iceCream->getXPos(), iceCream->getYPos() + 1)) {
        iceCream->setYPos(iceCream->getYPos() + 2);
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
                removeGameObject(objects[i]);
                i--;
            }
        }
    }
    if (makeNew) {
        makeNewPlatform(getLastPlatformHeight(), true);
        makeNew = false;
    }
    else {
        makeNew = true;
    }
    if (iceCream->getYPos() < 1) {
        status = 0;
    }
}

int IceCreamDrop::getRandomNumber(int lower, int higher) {
    return (rand() % (higher - lower)) + lower;
}
