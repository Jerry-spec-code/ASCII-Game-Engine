#ifndef ALIEN_H
#define ALIEN_H

#include "character.h"
using namespace std;

class Alien : public Character {
public:
    Alien(char c, int x, int y, int height = 1);
    ~Alien();
};

#endif
