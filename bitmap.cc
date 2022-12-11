#include "bitmap.h"

Bitmap::Bitmap() {}
Bitmap::~Bitmap() {}

Bitmap::Bitmap(std::initializer_list<tuple<int, int, char>> init) {
    for (auto elem : init) {
        map.push_back(elem);
    }
}

vector<tuple<int, int, char>> Bitmap::getMap() {
    return map;
}

void Bitmap::push_back(tuple<int, int, char> bit) {
    map.push_back(bit);
}

void Bitmap::remove(tuple<int, int, char> bit) {
    for (int i = 0; i < map.size(); i++) {
        if (bit == map[i]) {
            map.erase(map.begin() + i);
            i--;
        }
    }
}



