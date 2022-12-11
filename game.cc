#include <cstddef>
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameObject.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include <ncurses.h>

#include <iostream>
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::go() {
	shared_ptr<Display> display_border = make_shared<BorderDisplay>();
    display_border->display();
    shared_ptr<Display> display_objects = make_shared<GameDisplay>(objects);
    display_objects->display();
    shared_ptr<Display> display_status = make_shared<StatusDisplay>(3);
    display_status->display();
}

void Game::addGameObject(shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}
