#include "iceCreamDisplay.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include <memory>
#include <ncurses.h>

IceCreamDisplay::IceCreamDisplay(): display_border{make_shared<BorderDisplay>()}, 
display_status{make_shared<StatusDisplay>()}, display_objects{make_shared<GameDisplay>()} {}

void IceCreamDisplay::render() {
    display_border->display();
    display_objects->display();
    display_status->display();
    refresh();	
}

void IceCreamDisplay::updateStatus(vector<string> messages) {
    display_status->setMessages(messages);
}

vector<string> IceCreamDisplay::getStatus() {
    return display_status->getMessages();
}

void IceCreamDisplay::updateObjects(vector<shared_ptr<GameObject>> objects) {
    display_objects->setObjects(objects);
}
