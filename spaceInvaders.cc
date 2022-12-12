#include "spaceInvaders.h"
#include <ncurses.h>
#include "keyboard.h"
#include "spaceInvadersDisplay.h"
#include "action.h"
#include "rocketShip.h"
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

}

void SpaceInvaders::go() {
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    while (status != 0) {
        spaceInvadersDisplay->inProgress();
        display();
        clock_t t = clock();
        while (clock() - t < updateInterval) {
            noecho();
            Action action = input->getAction();	
            if (dynamic_cast<RocketShip *>(rocket.get())) {
    //             moveIceCream(action);
    //             if (status == 0) {
    //                 break;
    //             }
            }
    //         displayHelper();	
        }
    //     updateView();
        break;
    }
    display();
    sleep(5);
    endwin();
}

void SpaceInvaders::display() {
    spaceInvadersDisplay->updateObjects(getObjects());
    spaceInvadersDisplay->render();
}
