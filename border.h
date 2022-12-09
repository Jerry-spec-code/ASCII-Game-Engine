#ifndef BORDER_H
#define BORDER_H
#include "border.h"
#include "bitmap.h"
#include <vector>
#include <ncurses.h>

#include <iostream>
using namespace std;

class Border {
    const int borderLength = 80;
    const int borderWidth = 22;
    vector<shared_ptr<Bitmap> > borderInfo;
public:
    Border();
    ~Border();
    vector<shared_ptr<Bitmap> > getBorderInfo() {
        return borderInfo;
    }
};

#endif
