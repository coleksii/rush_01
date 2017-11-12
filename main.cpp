#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include "Network.hpp"


int main()
{
    RamMemory ram;
    Network net;
    ram.reload();
//    std::cout << ram.getVirt_UsedMemory() << std::endl;
//    std::cout << ram.getVirt_freeMemory() << std::endl;
//    std::cout << ram.getPhysical_memory() << std::endl;
//    std::cout << ram.getPhys_Used_memory() << std::endl;
//    std::cout << ram.getPhys_Unused_memory() << std::endl;
//    std::cout << ram.getPhys_Wired_memory() << std::endl;
    OSInfo os;
    printf("%s\n", net.getIn());
    printf("%s\n", net.getOut());
//    Ncurses curses;
//    curses.allplugins();

    return 0;
}