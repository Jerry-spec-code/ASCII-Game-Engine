#include <cstddef>
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameobject.h"
#include "borderDisplay.h"
#include <ncurses.h>

#include <iostream>
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::go() {
    shared_ptr<BorderDisplay> display_border = make_shared<BorderDisplay>();
    initscr();			/* Start curses mode 		  */
	display_border->display();
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

void Game::addGameObject(shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}
