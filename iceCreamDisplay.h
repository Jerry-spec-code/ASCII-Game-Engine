#ifndef ICECREAMDISPLAY_H
#define ICECREAMDISPLAY_H

#include "display.h"
#include <vector>
#include <memory>

class GameObject;

class IceCreamDisplay {
    shared_ptr<BorderDisplay> display_border;
    shared_ptr<StatusDisplay> display_status;
    shared_ptr<GameDisplay> display_objects;
public:
    IceCreamDisplay();
    void render();
    void updateStatus(vector<string> messages);
    vector<string> getStatus();
    void updateObjects(vector<shared_ptr<GameObject>> objects);
};

#endif
