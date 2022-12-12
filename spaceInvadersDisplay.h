#ifndef SPACEINVADERS_DISPLAY
#define SPACEINVADERS_DISPLAY

class BorderDisplay;
class StatusDisplay;
class GameDisplay;
class GameObject;

#include <memory>
#include <vector>
using namespace std;

class SpaceInvadersDisplay {
    shared_ptr<BorderDisplay> display_border;
    shared_ptr<StatusDisplay> display_status;
    shared_ptr<GameDisplay> display_objects;
public:
    SpaceInvadersDisplay();
    void render();
    void updateStatus(vector<string> messages);
    vector<string> getStatus();
    void updateObjects(vector<shared_ptr<GameObject>> objects);
    void inProgress(); 
private:
    void updateHelper(string msg1, string msg2, string msg3);
};

#endif
