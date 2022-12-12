#ifndef ICECREAMDISPLAY_H
#define ICECREAMDISPLAY_H

#include "display.h"
#include <vector>
#include <memory>

class GameObject;
class BorderDisplay;
class StatusDisplay;
class GameDisplay;

using namespace std;

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
    void vanishUpdate(int numOfPlatformsPassed);
    void hitFlyUpdate(int numOfPlatformsPassed);
    void inProgress();
private:
    void updateHelper(string msg1, string msg2, string msg3);
};

#endif
