#include "rocketShip.h"
#include "border.h"

RocketShip::RocketShip() {}

RocketShip::RocketShip(std::initializer_list<tuple<int, int, char>> init): Bitmap{init} {}

RocketShip::~RocketShip() {}

void RocketShip::setDirection(Direction direction) {
    this->direction = direction;
}

Direction RocketShip::getDirection() {
    return direction;
}

void RocketShip::rotate() {
    if (direction == Direction::NORTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            if (get<0>(map[i]) + 1 == this->getXPos()) {
                get<0>(map[i]) += 3;
            }
            else if (get<1>(map[i]) + 2 == this->getYPos()) {
                get<1>(map[i]) += 3;
            }
        }
        setMap(map);
        setDirection(Direction::EAST);
    }
    else if (direction == Direction::EAST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            if (get<0>(map[i]) - 2 == this->getXPos()) {
                get<0>(map[i]) -= 3;
            }
            else if (get<1>(map[i]) + 1 == this->getYPos()) {
                get<1>(map[i]) += 3;
            }
        }
        setMap(map);
        setDirection(Direction::SOUTH);
    }
    else if (direction == Direction::SOUTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            if (get<0>(map[i]) - 1 == this->getXPos()) {
                get<0>(map[i]) -= 3;
            }
            else if (get<1>(map[i]) - 2 == this->getYPos()) {
                get<1>(map[i]) -= 3;
            }
        }
        setMap(map);
        setDirection(Direction::WEST);
    }
    else if (direction == Direction::WEST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            if (get<0>(map[i]) + 2 == this->getXPos()) {
                get<0>(map[i]) += 3;
            }
            else if (get<1>(map[i]) - 1 == this->getYPos()) {
                get<1>(map[i]) -= 3;
            }
        }
        setMap(map);
        setDirection(Direction::NORTH);
    }
}

void RocketShip::move(Action action) {
    if (action == Action::LEFT && direction == Direction::EAST || 
        action == Action::RIGHT && direction == Direction::WEST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<1>(map[i])--;
        }
        this->setYPos(this->getYPos() - 1);
        setMap(map);
    }
    else if (action == Action::RIGHT && direction == Direction::EAST || 
        action == Action::LEFT && direction == Direction::WEST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<1>(map[i])++;
        }
        this->setYPos(this->getYPos() + 1);
        setMap(map);
    }
    else if (action == Action::LEFT && direction == Direction::NORTH || 
        action == Action::RIGHT && direction == Direction::SOUTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<0>(map[i])--;
        }
        this->setXPos(this->getXPos() - 1);
        setMap(map);
    }
    else if (action == Action::RIGHT && direction == Direction::NORTH || 
        action == Action::LEFT && direction == Direction::SOUTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<0>(map[i])++;
        }
        this->setXPos(this->getXPos() + 1);
        setMap(map);
    }
}

bool RocketShip::hitBorder(shared_ptr<Border> border) {
    vector<tuple<int, int, char>> map = getMap();
    for (int i = 0; i < map.size(); i++) {
        if(border->onBorder(get<1>(map[i]), get<0>(map[i]))) {
            return true;
        }
    }
    return false;
}
