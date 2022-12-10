#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    void display() {
        doDisplay();
    }
private:
    virtual void doDisplay() = 0;
};

#endif
