#ifndef COLLISION_H
#define COLLISION_H

#include <memory>
using namespace std;

class GameObject;

class Collision {
public:
    Collision();
    ~Collision();
    bool isColliding(shared_ptr<GameObject> obj1, shared_ptr<GameObject> obj2);
};

#endif
