#include <iostream> 
#include <ncurses.h>
#include <memory>
#include <string>
#include "game.h"
#include "gameObject.h"
#include "character.h"
#include "rectangle.h"
#include <typeinfo>

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    shared_ptr<Game> g = make_shared<Game>();
    shared_ptr<GameObject> iceCream = make_shared<Character>('O', 15, 5, 1);
    shared_ptr<GameObject> fly = make_shared<Rectangle>(10, 1, 3, 4, 1, 'A');
    g->addGameObject(iceCream);
    g->addGameObject(fly);
    initscr();			/* Start curses mode 		  */
    g->go();
    refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
    return 0;
}