#include "iceCreamDrop.h"
#include <ncurses.h>
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"
#include "gameObject.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"

IceCreamDrop::IceCreamDrop() {}
IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::position() {
    shared_ptr<GameObject> iceCream = make_shared<Character>('O', 15, 5, 1);
    shared_ptr<GameObject> fly = make_shared<Rectangle>(10, 1, 3, 4, 1, 'A');
    addGameObject(iceCream);
    addGameObject(fly);
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
