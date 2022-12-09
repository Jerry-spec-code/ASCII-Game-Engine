#include <cstddef>
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameobject.h"
#include <ncurses.h>

#include "iostream"
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::go() {
    setlocale(LC_ALL, "");
    initscr();
    // refresh();
    // endwin();
}

void Game::addGameObject(shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}
