#include "rectangle.h"
#include "border.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(char c, int length, int width, int topLeftX, int topLeftY, int height): length{length}, width{width}, 
c{c}, GameObject{topLeftX, topLeftY, height} {}
Rectangle::~Rectangle() {}

int Rectangle::getLength() {
    return length;
}

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(int width) {
    this->width = width;
}

void Rectangle::setLength(int length) {
    this->length = length;
}

char Rectangle::getCharacter() {
    return c;
}

void Rectangle::setCharacter(char c) {
    this->c = c;
}

void Rectangle::rotate() {}

void Rectangle::move(Action action) {}
void Rectangle::move(Direction direction) {}

bool Rectangle::hitBorder(shared_ptr<Border> border) {
    for (int i = getXPos(); i < getXPos() + length; i++) {
        for (int j = getYPos(); j < getYPos() + length; j++) {
            if(border->onBorder(j, i)) {
                return true;
            }
        }
    }
    return false;
}
