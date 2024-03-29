#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "action.h"
#include <string>

class Controller{
  float inputTime = -1;
  virtual Action action() = 0;
 public:
  Action getAction();
  virtual void setKey(char c, Action action);
  void setInputTime(float inputTime);
  float getInputTime();
  virtual ~Controller() = default;
};
#endif
