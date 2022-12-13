#ifndef BORDERDISPLAY_H
#define BORDERDISPLAY_H
#include "display.h"

class BorderDisplay : public Display {
public:
    BorderDisplay();
    ~BorderDisplay();
private:
    void doDisplay() override;
};

#endif
