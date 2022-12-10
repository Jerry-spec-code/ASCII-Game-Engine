#ifndef GAME_H
#define GAME_H
#include <cstddef>
#include <vector>
#include <memory>

using namespace std;

class GameObject;

class Game {
    vector<shared_ptr<GameObject>> objects;
public:
    Game();
    ~Game();
    void go();
    void addGameObject(shared_ptr<GameObject> obj);
};

#endif
