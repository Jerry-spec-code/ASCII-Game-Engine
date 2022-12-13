#include <iostream> 
#include <ncurses.h>
#include <memory>
#include <string>
#include "game.h"
#include "gameObject.h"
#include "character.h"
#include "rectangle.h"
#include <typeinfo>
#include "spaceInvaders.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    shared_ptr<Game> g = make_shared<SpaceInvaders>();
    g->position();
    g->go();
    return 0;
}
