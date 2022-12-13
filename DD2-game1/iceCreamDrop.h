#ifndef ICECREAMDROP_H
#define ICECREAMDROP_H
#include "game.h"
#include "action.h"
#include <vector>

#include <iostream>
using namespace std;

class GameObject;
class Border;
class IceCreamDisplay;

class IceCreamDrop : public Game {
    shared_ptr<GameObject> iceCream;
    shared_ptr<Border> border;
    shared_ptr<IceCreamDisplay> iceCreamDisplay;
    const int firstPlatformHeight = 10;
    const int offset = 2;
    const int lowerBoundHole;
    const int upperBoundHole;
    const int flyFrequency = 5; //Number of platforms passed per fly generated
    const int appleFrequency = 5; //Number of platforms passed per apple generated
    bool makeNew = false;
    int status = 1; //1 is still playing, 0 means lost.
    int updateInterval = 75000;
    int numOfPlatformsPassed = 0;
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
    void makeNewPlatform(int height);
    int getRandomNumber(int lower, int higher);
    void makeFly(int x, int y);
    bool atLastPlatform();
    bool hitFly();
    void moveIceCream(Action action);
    void displayHelper();
};

#endif
