#include "borderDisplay.h"
#include "bitmap.h"
#include "border.h"
#include <ncurses.h>
#include <memory>

#include <iostream>
using namespace std;

BorderDisplay::BorderDisplay() {}
BorderDisplay::~BorderDisplay() {}

void BorderDisplay::doDisplay() {
    shared_ptr<Border> border = make_shared<Border>();
    shared_ptr<Bitmap> map = border->getBorder();
    vector<tuple<int, int, char>> borderArray = map->getMap();
    for (int i = 0; i < borderArray.size(); i++) {
        mvaddch(get<0>(borderArray[i]), get<1>(borderArray[i]), get<2>(borderArray[i]));
    }
}   
