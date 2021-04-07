#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display
{
    private:
        std::string mMessage = std::string.Empty;
    public:
        void showMessage();
        void defMessage(std::string message);
};


#endif