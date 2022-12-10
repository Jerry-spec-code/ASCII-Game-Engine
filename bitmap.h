#ifndef BITMAP_H
#define BITMAP_H
#include "gameObject.h"
#include <memory>
#include <vector>

#include <iostream>
using namespace std;

class Bitmap: public GameObject {
    vector<tuple<int, int, char>> map;
public:
    Bitmap();
    Bitmap(std::initializer_list<tuple<int, int, char>> init);
    ~Bitmap();
    vector<tuple<int, int, char>> getMap();
    void push_back(tuple<int, int, char> bit);
    void remove(tuple<int, int, char> bit);
};

#endif
