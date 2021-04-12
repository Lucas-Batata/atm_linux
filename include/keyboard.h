#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <vector>

class Keyboard
{
private:
    unsigned int mTotalValue = 0;
public:
    unsigned int getTotalValue();
    void insertValue(int value);
    void removeLastValue();
    void clearKeyboard();
    int getKeyInput();
};

#endif