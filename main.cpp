#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"

int main()
{
    RamMemory ram;
    Ncurses curses;
    curses.allplugins();
    return 0;
}