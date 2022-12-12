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

void IceCreamDisplay::vanishUpdate(int numOfPlatformsPassed) {
    string platformMessage = "You passed " +  to_string(numOfPlatformsPassed) + " platforms";
    updateHelper("You disintegrated!", "Tough run.", platformMessage);
}

void IceCreamDisplay::hitFlyUpdate(int numOfPlatformsPassed) {
    string platformMessage = "You passed " +  to_string(numOfPlatformsPassed) + " platforms";
    updateHelper("You hit a fly!", "Tough run.", platformMessage);
}

void IceCreamDisplay::inProgress() {
    updateHelper("Game in progress.", "Keep going!", "");
}


void IceCreamDisplay::updateHelper(string msg1, string msg2, string msg3) {
    vector<string> messages = getStatus();
    messages.clear();
    messages.push_back(msg1);
    messages.push_back(msg2);
    messages.push_back(msg3);
    updateStatus(messages);
}
