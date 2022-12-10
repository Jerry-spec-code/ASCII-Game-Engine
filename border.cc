#include "border.h"
#include <memory>

Border::Border() {
    border = make_shared<Bitmap>();
    for (int i = 0; i < borderLength; i++) {
        for (int j = 0; j < borderWidth; j++) {
            if (isCorner(i, j)) {
                border->push_back(make_shared<tuple<int, int, char>>(i, j, '+'));
            }
            else if (isBorderRow(i, j)) {
                border->push_back(make_shared<tuple<int, int, char>>(i, j, '-'));
            }
            else if (isBorderColumn(i, j)) {
                border->push_back(make_shared<tuple<int, int, char>>(i, j, '|'));
            }
        }
    }
}

Border::~Border() {}

const int Border::getBorderLength() {
    return borderLength;
}

const int Border::getBorderWidth() {
    return borderWidth;
}

shared_ptr<Bitmap> Border::getBorder() {
    return border;
}

bool Border::isCorner(int i, int j) const {
    return i == 0 && j == 0 || i == borderLength - 1 && j == 0 || i == 0 && j == borderWidth - 1 || i == borderLength - 1 && j == borderWidth - 1;
}
bool Border::isBorderRow(int i, int j) const {
    return i == 0 || i == borderLength - 1;
}
bool Border::isBorderColumn(int i, int j) const {
    return j == 0 || j == borderWidth - 1;   
}
