#ifndef ICECREAM_H
#define ICECREAM_H
#include "character.h"
#include "action.h"

#include <memory>
using namespace std;
class Game;
class Border;

class IceCream : public Character {
public:
    IceCream(char c, int x, int y, int height = 1);
    ~IceCream();
    void updateIceCreamPosition(Action action, shared_ptr<Border> border);
};

#endif 
