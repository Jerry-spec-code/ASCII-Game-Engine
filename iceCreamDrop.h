#include "game.h"

#include <iostream>
using namespace std;

class GameObject;
class Border;

class IceCreamDrop : public Game {
    shared_ptr<GameObject> iceCream;
    shared_ptr<Border> border;
    const int firstPlatformHeight = 4;
    const int offset = 2;
    const int lowerBoundHole;
    const int upperBoundHole;
    bool makeNew = false;
    int status = 1; //1 is still playing, 0 means lost .
public:
    IceCreamDrop();
    ~IceCreamDrop();
    void position() override;
    void go() override;
private:
    void positionPlatforms();
    void positionIceCream();
    void updateView();
    int getLastPlatformHeight();
    void makeNewPlatform(int height, bool addFly = false);
    int getRandomNumber(int lower, int higher);
};
