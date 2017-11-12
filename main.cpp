#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include <limits.h>
#include <string>
#include "Text.hpp"


int main(int gv, char **av)
{

    if (gv > 1 && !strcmp(av[1], "-txt")) {
        Text text;
        text.printTextInfo();
        return (0);
    }

    Ncurses curses;
    curses.allplugins();

    return 0;
}