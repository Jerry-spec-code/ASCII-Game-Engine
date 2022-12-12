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
    wtimeout(stdscr, 5000);
    Action action = input->getAction();
    cout << "Hello" << endl;
    // while (action == Action::INVALID) {
    //     action = input->getAction();
    // }	
    status = 0;
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
    endwin();
}

void SpaceInvaders::display() {
    spaceInvadersDisplay->updateObjects(getObjects());
    spaceInvadersDisplay->render();
}
