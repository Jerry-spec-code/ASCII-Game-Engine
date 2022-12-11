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

IceCreamDrop::IceCreamDrop(): border{make_shared<Border>()}, lowerBoundHole{border->getBorderLength() / 4}, 
upperBoundHole{3 * (border->getBorderLength() / 4)}, 
iceCream{make_shared<Character>('O', (border->getBorderLength() - 2) / 2, firstPlatformHeight - 1, 1)} {}

IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::go() {
    initscr();			
    for (int i = 0; i < 3; i++) {
        shared_ptr<Display> display_border = make_shared<BorderDisplay>();
        display_border->display();
        shared_ptr<Display> display_objects = make_shared<GameDisplay>(getObjects());
        display_objects->display();
        shared_ptr<Display> display_status = make_shared<StatusDisplay>(3);
        display_status->display();
        refresh();			
        getch();
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
    shared_ptr<Border> border = make_shared<Border>();
    int i = firstPlatformHeight;
    while (i < border->getBorderHeight()) {
        i += offset;
    }
    return i - offset; 
}

void IceCreamDrop::makeNewPlatform(int y, bool fly = false) {
    int holeLocation = getRandomNumber(lowerBoundHole, upperBoundHole);
    addGameObject(make_shared<Rectangle>(holeLocation - 1, 1, 1, y, 1, '-'));
    addGameObject(make_shared<Rectangle>(border->getBorderLength() - 4 - holeLocation, 1, holeLocation + 3, y, 1, '-'));
}

void IceCreamDrop::updateView() {
    vector<shared_ptr<GameObject>> objects = getObjects();
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Character *>(objects[i].get()) || dynamic_cast<Rectangle *>(objects[i].get())) {
            objects[i]->setYPos(objects[i]->getYPos() - offset);
        }
        else if (dynamic_cast<Bitmap *>(objects[i].get())) { 
            Bitmap *bits = static_cast<Bitmap *> (objects[i].get());
            vector<tuple<int, int, char>> map = bits->getMap();
            for (int j = 0; j < map.size(); j++) {
                get<1>(map[j]) -= offset; 
            }
        }
    }
    makeNewPlatform(getLastPlatformHeight(), true);
    if (iceCream->getYPos() < 1) {
        status = 0;
    }
}

int IceCreamDrop::getRandomNumber(int lower, int higher) {
    return (rand() % higher) + lower;
}
