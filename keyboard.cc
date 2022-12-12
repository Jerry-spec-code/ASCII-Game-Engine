#include "keyboard.h"
#include <string>
#include <unistd.h>

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

Action Keyboard::action(){
  int n;
  while ( (n = getch()) == ERR ) {
    float time = getInputTime();
    if (time > 0) {        
        sleep(time);
        break;
    }
  }

  if ( mapping.find(n) != mapping.end() ){
    return mapping[n];
  }
  return Action::INVALID;
}
