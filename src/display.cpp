#include "display.h"

void Display::showMessage(std::string message)
{
    if(message == "clear")
    {
        std::system("clear");
    }
    else
    {
        std::cout << message;
    }
    
}
