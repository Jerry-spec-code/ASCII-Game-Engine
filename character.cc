#include "character.h"

Character::Character(char c, int x, int y, int height): c{c}, GameObject{x, y, height} {}
Character::~Character() {}

void Character::setCharacter(char c) {
    this->c = c;
}

char Character::getCharacter() {
    return c;
}

void Character::move(Action action) {}
void Character::move(Direction direction) {}