#ifndef ICECREAM_H
#define ICECREAM_H
#include "character.h"

using namespace std;

class IceCream : public Character {
public:
    IceCream(char c, int x, int y, int height = 1);
    ~IceCream();

};

#endif 
