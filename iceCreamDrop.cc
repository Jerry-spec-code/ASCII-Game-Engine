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

IceCreamDrop::IceCreamDrop() {}
IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::position() {
    positionPlatforms();
    positionIceCream();
}

void IceCreamDrop::positionIceCream() {
    shared_ptr<Border> border = make_shared<Border>();
    shared_ptr<GameObject> iceCream = make_shared<Character>('O', (border->getBorderLength() - 2) / 2, firstPlatformHeight - 1, 1);
    addGameObject(iceCream);
}

void IceCreamDrop::positionPlatforms() {
    shared_ptr<Border> border = make_shared<Border>();
    int lowerBoundHole = border->getBorderLength() / 4;
    int upperBoundHole = 3 * (border->getBorderLength() / 4);
    for (int i = firstPlatformHeight; i < border->getBorderHeight(); i += offset) {
        int holeLocation = getRandomNumber(lowerBoundHole, upperBoundHole);
        addGameObject(make_shared<Rectangle>(holeLocation, 1, 1, i, 1, '-'));
        addGameObject(make_shared<Rectangle>(border->getBorderLength() - 2 - holeLocation, 1, holeLocation, i, 1, '-'));
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

void IceCreamDrop::go() {
    initscr();			
	shared_ptr<Display> display_border = make_shared<BorderDisplay>();
    display_border->display();
    shared_ptr<Display> display_objects = make_shared<GameDisplay>(getObjects());
    display_objects->display();
    shared_ptr<Display> display_status = make_shared<StatusDisplay>(3);
    display_status->display();
    refresh();			
	getch();			
	endwin();	
}

int IceCreamDrop::getRandomNumber(int lower, int higher) {
    srand (time(NULL));
    return (rand() % higher) + lower;
}
