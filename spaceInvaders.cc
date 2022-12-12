#include "spaceInvaders.h"
#include <ncurses.h>
#include "keyboard.h"
#include "spaceInvadersDisplay.h"

#include <string>
#include <chrono>
#include <thread>

#include <iostream>
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;

SpaceInvaders::SpaceInvaders(): spaceInvadersDisplay{make_shared<SpaceInvadersDisplay>()} {}

SpaceInvaders::~SpaceInvaders() {}

void SpaceInvaders::position() {

}

void SpaceInvaders::go() {
    initscr();
    shared_ptr<Controller> input = make_shared<Keyboard>();
    while (status != 0) {
        spaceInvadersDisplay->inProgress();
    //     displayHelper();
    //     clock_t t = clock();
    //     while (clock() - t < updateInterval) {
    //         noecho();
    //         Action action = input->getAction();	
    //         if (dynamic_cast<IceCream *>(iceCream.get())) {
    //             moveIceCream(action);
    //             if (status == 0) {
    //                 break;
    //             }
    //         }
    //         if (atLastPlatform()) {
    //             updateView();
    //         }
    //         displayHelper();	
    //     }
    //     updateView();
        break;
    }
    display();
    sleep_for(5s);
    endwin();
}

void SpaceInvaders::display() {
    spaceInvadersDisplay->updateObjects(getObjects());
    spaceInvadersDisplay->render();
}
