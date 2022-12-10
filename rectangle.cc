#include "rectangle.h"

Rectangle::Rectangle(int length, int width, int topLeftX, int topLeftY, int height, char c): length{length}, width{width}, 
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
