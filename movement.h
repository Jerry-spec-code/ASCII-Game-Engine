#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
public:
    virtual ~Movement() {}
    void move() {
        doMove();
    }
private:
    virtual void doMove() = 0;
};

#endif
