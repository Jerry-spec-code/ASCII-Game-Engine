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
        if (dynamic_cast<Character *>(objects[i].get())) {
            displayCharacter(static_cast<Character &> (*objects[i]));
        }
        else if (dynamic_cast<Rectangle *>(objects[i].get())) { 
            displayRectangle(static_cast<Rectangle &> (*objects[i]));
        }
        else if (dynamic_cast<Bitmap *>(objects[i].get())) { 
            displayBitmap(static_cast<Bitmap &> (*objects[i]));
        }
    }
}   

void GameDisplay::displayCharacter(Character &c) {
    mvaddch(c.getYPos(), c.getXPos(), c.getCharacter());
}

void GameDisplay::displayRectangle(Rectangle &r) {
    for (int i = 0; i < r.getWidth(); i++) {
        for (int j = 0; j < r.getLength(); j++) {
            mvaddch(i + r.getYPos(), j + r.getXPos(), r.getCharacter());
        }
    }
}

void GameDisplay::displayBitmap(Bitmap &b) {
    vector<tuple<int, int, char>> map = b.getMap();
    for (int i = 0; i < map.size(); i++) {
        mvaddch(get<1>(map[i]), get<0>(map[i]), get<2>(map[i]));
    }
}