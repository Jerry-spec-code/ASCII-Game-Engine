#include "spaceInvaders.h"
#include <ncurses.h>
#include "keyboard.h"

SpaceInvaders::SpaceInvaders() {}

SpaceInvaders::~SpaceInvaders() {}

void SpaceInvaders::position() {

}

void SpaceInvaders::go() {
    // initscr();
    // shared_ptr<Controller> input = make_shared<Keyboard>();
    // while (status != 0) {
    //     iceCreamDisplay->inProgress();
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
    // }
    // displayHelper();
    // sleep_for(5s);
    // endwin();
}
