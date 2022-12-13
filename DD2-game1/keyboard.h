#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "controller.h"
#include <iostream>
#include <string>
#include <map>
#include <ncurses.h>

class Keyboard: public Controller{
  std::map<int,Action> mapping; 

  Action action() override;
  void setKey(char c, Action action) override;
 public:
  Keyboard();
};
#endif
