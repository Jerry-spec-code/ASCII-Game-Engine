#include <iostream> 
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameobject.h"
using namespace std;

int main() {
    unique_ptr<Game> g = make_unique<Game>();
    g->go();
    // unique_ptr<GameObject> obj = make_unique<GameObject>();
    // obj->running();
    return 0;
}