//Chad Lape
//utility.h
//general utilities for easier use in other things

#include <iostream>
#include <limits>

class Util
{
public:
    static void clear();
    //will clear the screen
    static void pause();
    //will pause till user hits enter
};

void Util::clear()
{
    for(int i = 0; i < 1000; i++)
    {
        std::cout << "\n";
    }
}
void Util::pause()
{
    std::cout << "\n\nPress Enter to Continue: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}