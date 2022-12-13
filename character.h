#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameObject.h"

#include <iostream>
#include <memory>
using namespace std;


class Border;

class Character: public GameObject {
    char c;
public:
    Character(char c, int x, int y, int height = 1);
    ~Character();
    void setCharacter(char c);
    char getCharacter();
    void move(Action action) override;
    void move(Direction direction) override;
    bool hitBorder(shared_ptr<Border> border) override;
};

#endif
