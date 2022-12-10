#include "gameObject.h"

GameObject::GameObject() {}
GameObject::GameObject(int x, int y, int height): x{x}, y{y}, height{height} {}
GameObject::~GameObject() {}

int GameObject::getHeight() {
    return height;
}

int GameObject::getXPos() {
    return x;
}

int GameObject::getYPos() {
    return y;
}

void GameObject::setHeight(int height) {
    this->height = height;
}

void GameObject::setXPos(int x) {
    this->x = x;
}

void GameObject::setYPos(int y) {
    this->y = y;
}

void GameObject::setPos(int x, int y) {
    setXPos(x);
    setYPos(y);
}

void GameObject::setPos(int x, int y, int height) {
    setXPos(x);
    setYPos(y);
    setHeight(height);
}
