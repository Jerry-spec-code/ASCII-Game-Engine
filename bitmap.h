#ifndef BITMAP_H
#define BITMAP_H
#include "gameobject.h"
#include <vector>

#include <iostream>
using namespace std;

class Bitmap: public GameObject {
    vector<shared_ptr<tuple<int, int, char>>> map;
public:
    Bitmap();
    Bitmap(std::initializer_list <shared_ptr<tuple<int, int, char>>> init);
    ~Bitmap();
    vector<shared_ptr<tuple<int, int, char>>> getMap();
    void push_back(shared_ptr<tuple<int, int, char>> bit);
    void remove(shared_ptr<tuple<int, int, char>> bit);
};

#endif
