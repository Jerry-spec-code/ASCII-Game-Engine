#include "collision.h"
#include "gameObject.h"
#include "character.h"
#include "rectangle.h"
#include "bitmap.h"

#include <memory>
#include <iostream>
using namespace std;

Collision::Collision() {}
Collision::~Collision() {}

bool Collision::isColliding(shared_ptr<GameObject> obj1, shared_ptr<GameObject> obj2) {
    if (dynamic_cast<Character *>(obj1.get())) {
        if (dynamic_cast<Character *>(obj2.get())) {
            return obj1->getXPos() == obj2->getXPos() && obj1->getYPos() == obj2->getYPos();
        }
        else if (dynamic_cast<Rectangle *>(obj2.get())) {
            Rectangle rect = static_cast<Rectangle &>(*obj2);
            return rect.getXPos() <= obj1->getXPos() && obj1->getXPos() < rect.getXPos() + rect.getLength()
                && rect.getYPos() <= obj1->getYPos() && obj1->getYPos() < rect.getYPos() + rect.getWidth();
        }
        else if (dynamic_cast<Bitmap *>(obj2.get())) {
            Bitmap bits = static_cast<Bitmap &>(*obj2);
            vector<tuple<int, int, char>> map = bits.getMap();
            for (int j = 0; j < map.size(); j++) {
                if (get<0>(map[j]) == obj1->getXPos() && get<1>(map[j]) == obj1->getYPos()) {
                    return true;
                }
            }
        }
    }
    else if (dynamic_cast<Character *>(obj2.get())) {
        return isColliding(obj2, obj1);
    }
    else if (dynamic_cast<Rectangle *>(obj1.get())) {
        Rectangle rect = static_cast<Rectangle &>(*obj1);
        if (dynamic_cast<Bitmap *>(obj2.get())) {
            Bitmap bits = static_cast<Bitmap &>(*obj2);
            vector<tuple<int, int, char>> map = bits.getMap();
            for (int j = 0; j < map.size(); j++) {
                if (rect.getXPos() <= get<0>(map[j]) && get<0>(map[j]) < rect.getXPos() + rect.getLength()
                && rect.getYPos() <= get<1>(map[j]) && get<1>(map[j]) < rect.getYPos() + rect.getWidth()) {
                    return true;
                }
            }
        }
        else if (dynamic_cast<Rectangle *>(obj2.get())) {
            Rectangle rect2 = static_cast<Rectangle &>(*obj2);

            // If one rectangle is to the left of the other
            if (rect.getXPos() > rect2.getXPos() + rect2.getLength()|| 
                rect2.getXPos() > rect.getXPos() + rect.getLength()) {
                return false;
            }
    
            // If one rectangle is above other
            if (rect.getYPos() > rect2.getYPos() + rect2.getWidth() || 
                rect2.getYPos() > rect.getYPos() + rect.getWidth()) {
                return false;
            }
    
            return true;   
        }
    }
    else if (dynamic_cast<Rectangle *>(obj2.get())) {
        return isColliding(obj2, obj1);
    }
    else if (dynamic_cast<Bitmap *>(obj1.get())) {
        if (dynamic_cast<Bitmap *>(obj2.get())) {
            Bitmap bits1 = static_cast<Bitmap &>(*obj1);
            Bitmap bits2 = static_cast<Bitmap &>(*obj2);
            vector<tuple<int, int, char>> map1 = bits1.getMap();
            vector<tuple<int, int, char>> map2 = bits2.getMap();
            for (int i = 0; i < map1.size(); i++) {
                for (int j = 0; j < map2.size(); j++) {
                    if (get<0>(map1[j]) == get<0>(map2[i]) && get<1>(map1[j]) == get<1>(map2[i])) {
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
}
