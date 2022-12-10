#include "gameDisplay.h"
#include "bitmap.h"
#include "rectangle.h"
#include "character.h"
#include <ncurses.h>
#include <memory>

#include <iostream>
using namespace std;

GameDisplay::GameDisplay() {}
GameDisplay::GameDisplay(vector<shared_ptr<GameObject>> objects): objects{objects} {}
GameDisplay::~GameDisplay() {}

void GameDisplay::setObjects(vector<shared_ptr<GameObject>> objects) {
    this->objects = objects;
}

void GameDisplay::doDisplay() {
    for (int i = 0; i < objects.size(); i++) {
        if (typeid(objects[i]) == typeid(shared_ptr<Character>)) {
            displayCharacter(static_cast<Character &> (*objects[i]));
        }
    }
}   

void GameDisplay::displayCharacter(Character &c) {
    mvaddch(c.getXPos(), c.getYPos(), c.getCharacter());
}
