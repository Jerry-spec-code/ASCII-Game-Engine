#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"

#include <iostream>
using namespace std;

class Character: public GameObject {
public:
    Character();
    ~Character();
};

#endif
