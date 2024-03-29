#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "display.h"
#include <memory>
#include <cstddef>
#include <vector>

using namespace std;

class Game;
class GameObject;
class Character;
class Rectangle;
class Bitmap;

class GameDisplay : public Display {
    vector<shared_ptr<GameObject>> objects;
public:
    GameDisplay();
    GameDisplay(vector<shared_ptr<GameObject>> objects);
    ~GameDisplay();
    void setObjects(vector<shared_ptr<GameObject>> objects);
private:
    void doDisplay() override;
    void clearScreen();
    void displayCharacter(Character &c);
    void displayRectangle(Rectangle &r);
    void displayBitmap(Bitmap &b);
};

#endif
