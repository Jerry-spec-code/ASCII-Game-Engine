#include "rectangle.h"

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
