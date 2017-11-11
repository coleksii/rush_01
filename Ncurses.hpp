//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#ifndef RUSH01_NCURSES_HPP
#define RUSH01_NCURSES_HPP

#include<curses.h>
#include <signal.h>
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include "IMonitorDisplay.hpp"
#include "CPU.hpp"

class Ncurses : public IMonitorDisplay
{
public:
    Ncurses();
    ~Ncurses();
    void allplugins() const;
private:
    WINDOW *_menu;
    WINDOW *_data;
    void init_visualisation() const;
    void printmenu() const;
    void printmenudata() const;
};


#endif //RUSH01_NCURSES_HPP
