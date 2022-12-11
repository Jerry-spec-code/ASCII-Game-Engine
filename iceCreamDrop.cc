#include "iceCreamDrop.h"
#include <ncurses.h>
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"

IceCreamDrop::IceCreamDrop() {}
IceCreamDrop::~IceCreamDrop() {}

void IceCreamDrop::go() {
    shared_ptr<GameObject> iceCream = make_shared<Character>('O', 15, 5, 1);
    shared_ptr<GameObject> fly = make_shared<Rectangle>(10, 1, 3, 4, 1, 'A');
    addGameObject(iceCream);
    addGameObject(fly);
    initscr();			/* Start curses mode 		  */
    refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}
