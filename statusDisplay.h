#ifndef STATUSDISPLAY_H
#define STATUSDISPLAY_H
#include "display.h"
#include <memory>
#include <cstddef>
#include <vector>
#include <string>

using namespace std;

class StatusDisplay : public Display {
    vector<string> messages;
public:
    StatusDisplay(int n);
    StatusDisplay(std::initializer_list<string> init);
    ~StatusDisplay();
    void setMessages(vector<string> messages);
    void addMessage(string message);
    vector<string> getMessages();
private:
    void doDisplay() override;
};

#endif
