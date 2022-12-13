#include "border.h"
#include <memory>

Border::Border() {
    border = make_shared<Bitmap>();
    for (int i = 0; i < borderHeight; i++) {
        for (int j = 0; j < borderLength; j++) {
            if (isCorner(i, j)) {
                border->push_back(tuple<int, int, char>(i, j, '+'));
            }
            else if (isBorderRow(i, j)) {
                border->push_back(tuple<int, int, char>(i, j, '-'));
            }
            else if (isBorderColumn(i, j)) {
                border->push_back(tuple<int, int, char>(i, j, '|'));
            }
        }
    }
}

Border::~Border() {}

const int Border::getBorderLength() {
    return borderLength;
}

const int Border::getBorderHeight() {
    return borderHeight;
}

shared_ptr<Bitmap> Border::getBorder() {
    return border;
}

bool Border::onBorder(int i, int j) const {
    return isCorner(i, j) || isBorderRow(i, j) || isBorderColumn(i, j);
}

bool Border::isCorner(int i, int j) const {
    return i == 0 && j == 0 || i == borderHeight - 1 && j == 0 || i == 0 && j == borderLength - 1 || i == borderHeight - 1 && j == borderLength - 1;
}
bool Border::isBorderRow(int i, int j) const {
    return i == 0 || i == borderHeight - 1;
}
bool Border::isBorderColumn(int i, int j) const {
    return j == 0 || j == borderLength - 1;   
}
