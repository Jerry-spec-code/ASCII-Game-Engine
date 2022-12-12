#include "statusDisplay.h"
#include "border.h"
#include <ncurses.h>
#include <memory>
#include <typeinfo>

#include <iostream>
using namespace std;

StatusDisplay::StatusDisplay() {}

StatusDisplay::StatusDisplay(std::initializer_list<string> init) {
    for (auto elem : init) {
        messages.push_back(elem);
    }
}

StatusDisplay::~StatusDisplay() {}

void StatusDisplay::setMessages(vector<string> messages) {
    this->messages = messages;
}

void StatusDisplay::addMessage(string message) {
    messages.push_back(message);
}

vector<string> StatusDisplay::getMessages() {
    return messages;
}

void StatusDisplay::doDisplay() {
    mvprintw(0, 0, "Hello");
    shared_ptr<Border> border = make_shared<Border>();
    for (int i = 0; i < messages.size(); i++) {
        mvprintw(border->getBorderHeight() + i, 0, messages[i].c_str());
    }
}   

