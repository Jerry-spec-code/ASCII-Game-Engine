#include "bullet.h"

Bullet::Bullet(char c, int x, int y, int height): Character{c, x, y, height} {}

Bullet::~Bullet() {}

void Bullet::move(Direction direction) {
    if (direction == Direction::NORTH) {
        this->setYPos(this->getYPos() - 1);
    }
    if (direction == Direction::SOUTH) {
        this->setYPos(this->getYPos() + 1);
    }
    if (direction == Direction::EAST) {
        this->setXPos(this->getXPos() + 1);
    }
    if (direction == Direction::WEST) {
        this->setXPos(this->getXPos() - 1);
    }
}

void Bullet::setDirection(Direction direction) {
    this->direction = direction;
}

Direction Bullet::getDirection() {
    return direction;
}
