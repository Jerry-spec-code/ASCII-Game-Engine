#include "gameDisplay.h"
#include "bitmap.h"
#include "rectangle.h"
#include "character.h"
#include <ncurses.h>
#include <memory>
#include <typeinfo>

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
        auto x = dynamic_cast<Character &>(*objects[i]);
        if (typeid(x) == typeid(Character)) {
            cout << "Compiler is a liar" << endl;
        }
        if (typeid(*objects[i]) == typeid(Character)) {
            displayCharacter(static_cast<Character &> (*objects[i]));
        }
        else {
            cout << typeid(*objects[i]).name() << endl;
            cout << typeid(Character).name() << endl;
            break;
        }
    }
}   

void GameDisplay::displayCharacter(Character &c) {
    mvaddch(c.getXPos(), c.getYPos(), c.getCharacter());
}
