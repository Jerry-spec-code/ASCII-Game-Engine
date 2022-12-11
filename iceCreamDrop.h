#include "game.h"

#include <iostream>
using namespace std;

class IceCreamDrop : public Game {
public:
    IceCreamDrop();
    ~IceCreamDrop();
    void go() override;
};
