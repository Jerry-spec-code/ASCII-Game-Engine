#include "gameDisplay.h"
#include "gameObject.h"
#include "bitmap.h"
#include "border.h"
#include "rectangle.h"
#include "character.h"
#include <ncurses.h>
#include <memory>
#include <typeinfo>
#include <vector>

#include <iostream>
using namespace std;

GameDisplay::GameDisplay() {}
GameDisplay::GameDisplay(vector<shared_ptr<GameObject>> objects): objects{objects} {}
GameDisplay::~GameDisplay() {}

void GameDisplay::setObjects(vector<shared_ptr<GameObject>> objects) {
    this->objects = objects;
}

void GameDisplay::doDisplay() {
    clearScreen();
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
    shared_ptr<Border> border = make_shared<Border>();
    if(!border->onBorder(c.getYPos(), c.getXPos())) {
        mvaddch(c.getYPos(), c.getXPos(), c.getCharacter());
    }
}

void GameDisplay::clearScreen() {
    shared_ptr<Border> border = make_shared<Border>();
    for (int i = 0; i < border->getBorderHeight(); i++) {
        for (int j = 0; j < border->getBorderLength(); j++) {
            if(!border->onBorder(i, j)) {
                mvaddch(i, j, ' ');
            }
        }
    }
}

void GameDisplay::displayRectangle(Rectangle &r) {
    shared_ptr<Border> border = make_shared<Border>();
    for (int i = 0; i < r.getWidth(); i++) {
        for (int j = 0; j < r.getLength(); j++) {
            if(!border->onBorder(i + r.getYPos(), j + r.getXPos())) {
                mvaddch(i + r.getYPos(), j + r.getXPos(), r.getCharacter()); 
            }
        }
    }
}

void GameDisplay::displayBitmap(Bitmap &b) {
    shared_ptr<Border> border = make_shared<Border>();
    vector<tuple<int, int, char>> map = b.getMap();
    for (int i = 0; i < map.size(); i++) {
        if(!border->onBorder(get<1>(map[i]), get<0>(map[i]))) {
            mvaddch(get<1>(map[i]), get<0>(map[i]), get<2>(map[i]));
        }
    }
}
