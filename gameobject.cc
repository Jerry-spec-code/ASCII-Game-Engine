#include "gameobject.h"

GameObject::GameObject() {}
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
