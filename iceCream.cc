#include "iceCream.h"
#include "border.h"

#include <memory>
using namespace std;

IceCream::IceCream(char c, int x, int y, int height): Character{c, x, y, height} {}

IceCream::~IceCream() {}

void IceCream::updateIceCreamPosition(Action action, shared_ptr<Border> border, bool fall) {
    if(action == Action::RIGHT) {
        this->setXPos(this->getXPos() + 1);
        if(border->onBorder(this->getYPos(), this->getXPos())) {
            this->setXPos(1);
        }
    }
    else if (action == Action::LEFT) {
        this->setXPos(this->getXPos() - 1);
        if(border->onBorder(this->getYPos(), this->getXPos())) {
            this->setXPos(border->getBorderLength() - 2);
        }
    }
    if (fall) {
        this->setYPos(this->getYPos() + 2);
    }   
}
