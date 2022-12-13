#include "controller.h"

Action Controller::getAction(){
  return action(); 
}

void Controller::setInputTime(float inputTime) {
  this->inputTime = inputTime;
}

float Controller::getInputTime() {
  return inputTime;
}

void Controller::setKey(char c, Action action) {}
