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

#include <iostream>
using namespace std;

IceCreamDrop::IceCreamDrop(): border{make_shared<Border>()}, lowerBoundHole{border->getBorderLength() / 4}, 
upperBoundHole{3 * (border->getBorderLength() / 4)}, iceCreamDisplay{make_shared<IceCreamDisplay>()} {
    iceCream = make_shared<IceCream>('O', (border->getBorderLength() - 2) / 2, firstPlatformHeight - 1, 1);
}

IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::go() {			
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    while (status != 0) {
        iceCreamDisplay->updateObjects(getObjects());
        iceCreamDisplay->render();
        clock_t t = clock();
        while (clock() - t < updateInterval) {
            noecho();
            Action action = input->getAction();	
            if (dynamic_cast<IceCream *>(iceCream.get())) {
                IceCream cream = static_cast<IceCream &>(*iceCream);
                bool fall = isEmpty(iceCream->getXPos(), iceCream->getYPos() + 1) && !atLastPlatform();
                cream.updateIceCreamPosition(action, border, fall);
            }
            if (atLastPlatform()) {
                updateView();
            }
            iceCreamDisplay->updateObjects(getObjects());
            iceCreamDisplay->render();	
        }
        updateView();
    }
    endwin();			
}

bool IceCreamDrop::atLastPlatform() {
    return iceCream->getYPos() + 1 == getLastPlatformHeight();
}

// void IceCreamDrop::display() {
//     shared_ptr<BorderDisplay> display_border = make_shared<BorderDisplay>();
//     shared_ptr<StatusDisplay> display_status = make_shared<StatusDisplay>(); 
//     shared_ptr<GameDisplay> display_objects = make_shared<GameDisplay>();
//     display_objects->setObjects(getObjects());
//     display_border->display();
//     display_objects->display();
//     display_status->display();
//     refresh();	
// }

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
        addGameObject(make_shared<Rectangle>('X', 3, 1, x, y));
    }
}

// void IceCreamDrop::updateIceCreamPosition(Action action) {
//     if(action == Action::RIGHT) {
//         iceCream->setXPos(iceCream->getXPos() + 1);
//         if(border->onBorder(iceCream->getYPos(), iceCream->getXPos())) {
//             iceCream->setXPos(1);
//         }
//     }
//     else if (action == Action::LEFT) {
//         iceCream->setXPos(iceCream->getXPos() - 1);
//         if(border->onBorder(iceCream->getYPos(), iceCream->getXPos())) {
//             iceCream->setXPos(border->getBorderLength() - 2);
//         }
//     }
//     if (isEmpty(iceCream->getXPos(), iceCream->getYPos() + 1) && !atLastPlatform()) {
//         iceCream->setYPos(iceCream->getYPos() + 2);
//         // iceCreamDisplay->updateStatus();
//     }
// }

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
        status = 0;
    }
}

int IceCreamDrop::getRandomNumber(int lower, int higher) {
    return (rand() % (higher - lower)) + lower;
}
