#include "statusDisplay.h"
#include "border.h"
#include <ncurses.h>
#include <memory>
#include <typeinfo>

#include <iostream>
using namespace std;

StatusDisplay::StatusDisplay(int n) {
    for (int i = 0; i < n; i++) {
        messages.push_back("");
    }
}

StatusDisplay::StatusDisplay(std::initializer_list<string> init) {
    for (auto elem : init) {
        messages.push_back(elem);
    }
}

StatusDisplay::~StatusDisplay() {}

void StatusDisplay::setMessages(vector<string> messages) {
    this->messages = messages;
}

vector<string> StatusDisplay::getMessages() {
    return messages;
}

void StatusDisplay::doDisplay() {
    shared_ptr<Border> border = make_shared<Border>();
    for (int i = 0; i < messages.size(); i++) {
        mvprintw(border->getBorderHeight() + i, 0, messages[i].c_str());
    }
}   

