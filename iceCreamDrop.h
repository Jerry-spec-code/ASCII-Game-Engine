#include "game.h"

#include <iostream>
using namespace std;

class IceCreamDrop : public Game {
    int firstPlatformHeight = 2;
    int offset = 2;
public:
    IceCreamDrop();
    ~IceCreamDrop();
    void position() override;
    void go() override;
private:
    void positionPlatforms();
    void positionIceCream();
    int getLastPlatformHeight();
};
