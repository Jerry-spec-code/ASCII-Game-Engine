#ifndef BITMAP_H
#define BITMAP_H
#include "gameobject.h"
#include <vector>

#include <iostream>
using namespace std;

class Bitmap: public GameObject {
    vector<shared_ptr<tuple<int, int, char>>> maps;
public:
    Bitmap();
    Bitmap(std::initializer_list <shared_ptr<tuple<int, int, char>>> init);
    ~Bitmap();
};

#endif
