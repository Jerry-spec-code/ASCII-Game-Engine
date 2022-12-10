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
    WINDOW *win = newwin(border->getBorderLength(), border->getBorderWidth(), 0, 0);
    printw("Hello World !!!");	/* Print Hello World		  */
    shared_ptr<Bitmap> map = border->getBorder();
    vector<shared_ptr<tuple<int, int, char>>> borderArray = map->getMap();
    for (int i = 0; i < borderArray.size(); i++) {
        mvaddch(std::get<0>(*borderArray[i]), std::get<1>(*borderArray[i]), std::get<2>(*borderArray[i]));
    }
}   
