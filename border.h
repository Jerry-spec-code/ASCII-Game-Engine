#ifndef BORDER_H
#define BORDER_H
#include "border.h"
#include "bitmap.h"
#include <memory>
#include <vector>
#include <ncurses.h>

#include <iostream>
using namespace std;

class Border {
    const int borderLength = 80;
    const int borderHeight = 22;
    shared_ptr<Bitmap> border;
public:
    Border();
    ~Border();
    const int getBorderLength();
    const int getBorderHeight();
    shared_ptr<Bitmap> getBorder();
    bool isCorner(int i, int j) const;
    bool isBorderRow(int i, int j) const;
    bool isBorderColumn(int i, int j) const;
};

#endif
