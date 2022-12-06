#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "game.h"

#include <iostream>
using namespace std;

class GameObject : public Game {
public:
    GameObject() {}
    ~GameObject() {}
    void running() {
        run();
    }
private:
    void run() override {
        cout << "ran here!" << endl;
    }
};

#endif
