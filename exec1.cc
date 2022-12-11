#include <iostream> 
#include <ncurses.h>
#include <memory>
#include <string>
#include "game.h"
#include "gameObject.h"
#include "character.h"
#include "rectangle.h"
#include <typeinfo>

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    shared_ptr<Game> g = make_shared<Game>();
    shared_ptr<GameObject> iceCream = make_shared<Character>('O', 15, 5, 1);
    shared_ptr<GameObject> fly = make_shared<Rectangle>('X', 5, 15, 1);
    g->addGameObject(iceCream);
    g->addGameObject(fly);
    g->go();
    return 0;
}