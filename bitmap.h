#ifndef BITMAP_H
#define BITMAP_H
#include "gameObject.h"
#include <memory>
#include <vector>

#include <iostream>
using namespace std;

class Border;

class Bitmap: public GameObject {
    vector<tuple<int, int, char>> map;
public:
    Bitmap();
    Bitmap(std::initializer_list<tuple<int, int, char>> init);
    ~Bitmap();
    vector<tuple<int, int, char>> getMap();
    void setMap(vector<tuple<int, int, char>> map); 
    void push_back(tuple<int, int, char> bit);
    void remove(tuple<int, int, char> bit);
    void rotate() override;
    void move(Action action) override;
    void move(Direction direction) override;
    bool hitBorder(shared_ptr<Border> border) override;
};

#endif
