#include "spaceInvaders.h"
#include <ncurses.h>
#include "keyboard.h"
#include "spaceInvadersDisplay.h"
#include "action.h"
#include "rocketShip.h"
#include "bullet.h"
#include "spaceAlien.h"
#include <unistd.h>

#include <string>
#include <chrono>
#include <thread>

#include <iostream>
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;

SpaceInvaders::SpaceInvaders(): spaceInvadersDisplay{make_shared<SpaceInvadersDisplay>()}, 
rocket{make_shared<RocketShip>()} {}

SpaceInvaders::~SpaceInvaders() {}

void SpaceInvaders::position() {
    // Position the rocket ship
    // Position 3 columns of aliens on each side. 
}

void SpaceInvaders::go() {
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    input->setInputTime(5000);
    wtimeout(stdscr, input->getInputTime());
    while (status != 0) {
        spaceInvadersDisplay->inProgress();
        display();
        clock_t t = clock();
        while (clock() - t < updateInterval) {
            noecho();
            Action action = input->getAction();	
            moveOrShoot(action);
            if (status == 0) {
                break;
            }
            display();	
        }
        updateView();
    }
    display();
    sleep_for(5s);
    endwin();
}

void SpaceInvaders::display() {
    spaceInvadersDisplay->updateObjects(getObjects());
    spaceInvadersDisplay->render();
}

void SpaceInvaders::moveOrShoot(Action action) {
    if (dynamic_cast<RocketShip *>(rocket.get())) {
        if (action == Action::UP) {
            // Spawn a bullet 
        }
        else {
            RocketShip *ship = static_cast<RocketShip *>(rocket.get());
            ship->move(action);
        }
    }
    //Check if any part collides with the border.
}

void SpaceInvaders::updateView() {
    //Spawn another row of aliens on each side. (Easy method, just spawn at the borders).
    // Everything to the left of the rocket, move right. 
    // Everything to the right of the rocket, move left. 
    // If a bullet collides with an alien, destroy both.
    // If an alien collides with anything other than you or the border, you lose. 
}
