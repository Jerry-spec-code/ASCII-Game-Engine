#include <cstddef>
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameObject.h"
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "border.h"
#include "statusDisplay.h"
#include <ncurses.h>

#include <iostream>
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::position() {}

// Default implementation
void Game::go() {
    initscr();		
	shared_ptr<Display> display_border = make_shared<BorderDisplay>();
    display_border->display();
    shared_ptr<Display> display_objects = make_shared<GameDisplay>(objects);
    display_objects->display();
    shared_ptr<Display> display_status = make_shared<StatusDisplay>(3);
    display_status->display();
    refresh();		
	getch();		
	endwin();		
}

void Game::addGameObject(shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}

void Game::removeGameObject(shared_ptr<GameObject> obj) {
    for (int i = 0; i < objects.size(); i++) {
        if (obj == objects[i]) {
            objects.erase(objects.begin() + i);
        }
    }
}

vector<shared_ptr<GameObject>> Game::getObjects() {
    return objects; 
}

bool Game::isEmpty(int x, int y) {
    shared_ptr<Border> border = make_shared<Border>();
    if(border->onBorder(y, x)) {
        return false;
    }
    for (int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Character *>(objects[i].get())) {
            if (objects[i]->getYPos() == y && objects[i]->getXPos() == x) {
                return false;
            }
        }
        else if (dynamic_cast<Rectangle *>(objects[i].get())) {
            Rectangle rect = static_cast<Rectangle &>(*objects[i]);
            if (rect.getXPos() < x && x < rect.getXPos() + rect.getLength()
                && rect.getYPos() < y && y < rect.getYPos() + rect.getWidth()) {
                    return false;
            }
        }
        else if (dynamic_cast<Bitmap *>(objects[i].get())) { 
            Bitmap bits = static_cast<Bitmap &>(*objects[i]);
            vector<tuple<int, int, char>> map = bits.getMap();
            for (int j = 0; j < map.size(); j++) {
                if (get<0>(map[j]) == x && get<1>(map[j]) == y) {
                    return false;
                }
            }
        }
    }
    return true;
}
