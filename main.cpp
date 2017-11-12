#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"

int main()
{
    OSInfo os;
    Ncurses curses;
    curses.allplugins();
    std::cout << os.getSysname() << std::endl;
    return 0;
}