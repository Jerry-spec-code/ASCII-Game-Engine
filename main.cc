#include <iostream> 
#include <ncurses.h>
#include <memory>
#include "game.h"
#include "gameobject.h"
using namespace std;

int main() {
    shared_ptr<Game> g = make_shared<Game>();
    g->go();
    return 0;
}