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
    bool onBorder(int y, int x) const;
    bool isCorner(int y, int xj) const;
    bool isBorderRow(int y, int x) const;
    bool isBorderColumn(int y, int x) const;
};

#endif
