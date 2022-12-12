#include "spaceInvadersDisplay.h"
#include "gameObject.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include <memory>
#include <string>
#include <ncurses.h>

SpaceInvadersDisplay::SpaceInvadersDisplay(): display_border{make_shared<BorderDisplay>()}, 
display_status{make_shared<StatusDisplay>()}, display_objects{make_shared<GameDisplay>()} {}

void SpaceInvadersDisplay::render() {
    display_border->display();
    display_objects->display();
    display_status->display();
    refresh();	
}

void SpaceInvadersDisplay::updateStatus(vector<string> messages) {
    display_status->setMessages(messages);
}

vector<string> SpaceInvadersDisplay::getStatus() {
    return display_status->getMessages();
}

void SpaceInvadersDisplay::updateObjects(vector<shared_ptr<GameObject>> objects) {
    display_objects->setObjects(objects);
}

void SpaceInvadersDisplay::inProgress() {
    updateHelper("Shooting in progress.", "Stay away from the bullets!", "");
}

void SpaceInvadersDisplay::updateHelper(string msg1, string msg2, string msg3) {
    vector<string> messages = getStatus();
    messages.clear();
    messages.push_back(msg1);
    messages.push_back(msg2);
    messages.push_back(msg3);
    updateStatus(messages);
}

