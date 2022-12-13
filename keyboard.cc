#include "keyboard.h"
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <ncurses.h>

#include <iostream>
using namespace std;

Keyboard::Keyboard() {
  setlocale(LC_ALL, "");
  mapping['w'] = Action::UP;
  mapping['d'] = Action::RIGHT;
  mapping['s'] = Action::DOWN;
  mapping['a'] = Action::LEFT;
  mapping[KEY_UP] = Action::UP;
  mapping[KEY_RIGHT] = Action::RIGHT;
  mapping[KEY_DOWN] = Action::DOWN;
  mapping[KEY_LEFT] = Action::LEFT;
}

void Keyboard::setKey(char c, Action action) {
  mapping[c] = action;
}

Action Keyboard::action(){
  int n = -1;
  if (getInputTime() < 0) {
    while ((n = getch()) == ERR) {
      continue;
    }
  }
  else {
    n = getch();
  }
  if ( mapping.find(n) != mapping.end() ){
    return mapping[n];
  }
  else if (n == -1) {
    return Action::NONE;
  }
  return Action::INVALID;
}
