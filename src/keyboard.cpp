#include "../include/keyboard.h"
#include <iostream>

int Keyboard::getKeyInput()
{
    //std::vector<char> validNums = {'1','2','3','4','5','6','7','8','9','0'};
    char num;

    std::cin >> num;
       
    // for(auto i : validNums)
    // {
    //     if(i == num)
    //     {
    //         //If the CHAR is equal a number, returns it.
    //         return num - '0';
    //         break;
    //     }
    // }

    if(std::size_t(num) >= 48)
    {
        if(std::size_t(num) <= 57)
        {
            //If the CHAR is equal a number, returns it.
            return num - '0';
        }
    }

    if(num == 'c')
    {
        //Clear Keyboard value
        return -1;
    }
    
    if(num == 'r')
    {
        //Remove last value
        return -2;
    }

    //Unexpected key pressed
    return -3;

}

void Keyboard::insertValue(int value)
{
    //Insere o valor como unidade
    mTotalValue *= 10;
    mTotalValue += value;
}

void Keyboard::removeLastValue()
{
    //Remove a unidade do valor total
    mTotalValue = mTotalValue - (mTotalValue % 10);   
    mTotalValue /= 10;
}

void Keyboard::clearKeyboard()
{
    mTotalValue = 0;
}

unsigned int Keyboard::getTotalValue()
{
    return mTotalValue;
}