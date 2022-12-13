#include "rocketShip.h"

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
        setDirection(Direction::EAST);
    }
    else if (direction == Direction::EAST) {
        setDirection(Direction::SOUTH);
    }
    else if (direction == Direction::SOUTH) {
        setDirection(Direction::WEST);
    }
    else if (direction == Direction::WEST) {
        setDirection(Direction::NORTH);
    }
}

void RocketShip::move(Action action) {
    if (action == Action::LEFT && direction == Direction::EAST || 
        action == Action::RIGHT && direction == Direction::WEST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<0>(map[i])--;
        }
        setMap(map);
    }
    else if (action == Action::RIGHT && direction == Direction::EAST || 
        action == Action::LEFT && direction == Direction::WEST) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<0>(map[i])++;
        }
        setMap(map);
    }
    else if (action == Action::LEFT && direction == Direction::NORTH || 
        action == Action::RIGHT && direction == Direction::SOUTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<1>(map[i])--;
        }
        setMap(map);
    }
    else if (action == Action::RIGHT && direction == Direction::NORTH || 
        action == Action::LEFT && direction == Direction::SOUTH) {
        vector<tuple<int, int, char>> map = getMap();
        for (int i = 0; i < map.size(); i++) {
            get<1>(map[i])++;
        }
        setMap(map);
    }
}
