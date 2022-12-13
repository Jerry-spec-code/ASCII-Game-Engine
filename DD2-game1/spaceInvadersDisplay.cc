#include "spaceInvadersDisplay.h"
#include "gameObject.h"
#include "gameDisplay.h"
#include "borderDisplay.h"
#include "statusDisplay.h"
#include <memory>
#include <string>
#include <ncurses.h>
#include <vector>

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
    updateHelper("Shoot the aliens!", "Don't let hit you!", "Don't run into the walls!");
}

void SpaceInvadersDisplay::hitBorder(int numOfAliensHit) {
    string alienMessage = "You shot " +  to_string(numOfAliensHit) + " aliens";
    updateHelper("You hit the border!", alienMessage, "Better luck next time!");
}

void SpaceInvadersDisplay::hitAlien(int numOfAliensHit) {
    string alienMessage = "You shot " +  to_string(numOfAliensHit) + " aliens";
    updateHelper("You hit an alien!", alienMessage, "Better luck next time!");
}

void SpaceInvadersDisplay::updateHelper(string msg1, string msg2, string msg3) {
    vector<string> messages = getStatus();
    messages.clear();
    messages.push_back(msg1);
    messages.push_back(msg2);
    messages.push_back(msg3);
    updateStatus(messages);
}

