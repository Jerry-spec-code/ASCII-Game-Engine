#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameObject.h"

#include <iostream>
using namespace std;

class Character: public GameObject {
    char c;
public:
    Character(char c, int x, int y, int height = 1);
    ~Character();
    void setCharacter(char c);
    char getCharacter();
};

#endif
