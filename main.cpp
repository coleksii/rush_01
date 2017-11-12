#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include <limits.h>

int main()
{
    RamMemory ram;

    ram.reload();
//    OSInfo os;
//    Ncurses curses;
//    curses.allplugins();
    printf("%lld MB\n", (ram.getPhysical_memory() >> 20ULL));
    return 0;
}