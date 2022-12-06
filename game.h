#ifndef GAME_H
#define GAME_H
#include <cstddef>

class Game {
public:
    Game();
    ~Game();
    void go();
private:
    virtual void run() {};
};

#endif
