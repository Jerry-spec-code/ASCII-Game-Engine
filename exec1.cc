#include <iostream> 
#include <ncurses.h>
#include <memory>
#include <string>
#include "game.h"
#include "gameObject.h"
#include "character.h"
#include <typeinfo>

#include <iostream>
using namespace std;

//Flags
// Default space invaders.
// -inv (space invaders)
// -drop (ice cream drop)

int main(int argc, char* argv[]) {
    if (argc > 2) {
        cerr << "Too many command line arguments";
        return 1;
    }
    if (argc == 1 || string(argv[1]) == "-drop") {
        shared_ptr<Game> g = make_shared<Game>();
        shared_ptr<GameObject> iceCream = make_shared<Character>('O', 15, 5, 1);
        shared_ptr<GameObject> fly = make_shared<Character>('X', 5, 15, 1);
        g->addGameObject(iceCream);
        g->addGameObject(fly);
        g->go();
    }
    else if(string(argv[1]) == "-inv") {
        shared_ptr<Game> g = make_shared<Game>();
        g->go();
    }
    else {
        cerr << "Invalid command line arguments";
        return 1;
    }
    return 0;
}