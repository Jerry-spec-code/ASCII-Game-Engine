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
    mvaddch(c.getXPos(), c.getYPos(), c.getCharacter());
}

void GameDisplay::displayRectangle(Rectangle &r) {

}

void GameDisplay::displayBitmap(Bitmap &b) {

}
