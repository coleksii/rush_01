//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#ifndef RUSH01_NCURSES_HPP
#define RUSH01_NCURSES_HPP

#include<curses.h>
#include <signal.h>
#include "RamMemory.hpp"

class Ncurses
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