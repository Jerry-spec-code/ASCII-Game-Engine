#include <cstddef>
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameobject.h"
#include <ncurses.h>

#include <iostream>
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::go() {
    initscr();			/* Start curses mode 		  */
    raw();
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

void Game::addGameObject(shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}
