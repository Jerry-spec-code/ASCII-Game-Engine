#include "fly.h"

#include <memory>
using namespace std;

Fly::Fly() {}
Fly::Fly(char c, int length, int width, int x, int y, int height): 
Rectangle{c, length, width, x, y, height} {}

Fly::~Fly() {}
