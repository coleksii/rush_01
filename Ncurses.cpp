//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#include "Ncurses.hpp"
#include <zconf.h>

void Ncurses::init_visualisation() const
{
    noecho();
//    cbreak();
    signal(SIGWINCH, NULL);
    curs_set(0);
    start_color();
    keypad(_menu, TRUE);
    nodelay(_menu, TRUE);
    init_pair(1, COLOR_BLACK, 8);//for margins of menu
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);//for menu text
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::printmenudata() const
{
    wattron(_menu, COLOR_PAIR(2));

}

void Ncurses::allplugins() const
{
    RamMemory ram;
    UserInfo user;
    OSInfo os;
    CPU cpu;

    wattron(_data, COLOR_PAIR(3));
    mvwprintw(_data, 2, 4, "Username: %s", user.getUser());
    mvwprintw(_data, 3, 4, "Hostname: %s", user.getHost());
    mvwprintw(_data, 7, 4, "Sysname: %s", os.getSysname());
    mvwprintw(_data, 8, 4, "Nodename: %s", os.getNodename());
    mvwprintw(_data, 9, 4, "Release: %s", os.getRelease());
    mvwprintw(_data, 10, 4, "Version: %s", os.getVersion());
    mvwprintw(_data, 11, 4, "Machine: %s", os.getMachine());
    while (1)
    {
        mvwprintw(_data, 5, 4, "Free memory: %lld kb     ", ram.getFreeMemory() / 1024);
        mvwprintw(_data, 6, 4, "Used memory: %lld kb     ", ram.getUsedMemore() / 1024);
        mvwprintw(_data, 12, 4, "CPU Load: %.2f", cpu.get_cpu());
        ram.reload();
        cpu.reload();
        wrefresh(_data);
        sleep(1);
    }
}

void Ncurses::printmenu() const
{
    wattron(_menu, COLOR_PAIR(1) | A_BOLD);
    wattron(_data, COLOR_PAIR(1) | A_BOLD);
    for (int y = 0; y < 70; y++)
    {
        mvwaddch(_menu, y, 0, ' ');
        mvwaddch(_menu, y, 27, ' ');
        mvwaddch(_data, y, 99, ' ');
    }
    for (int x = 0; x < 28; x++)
    {
        mvwaddch(_menu, 0, x, ' ' | A_BOLD);
        mvwaddch(_menu, 69, x, ' '| A_BOLD);
    }
    for (int x = 0; x < 100; x++)
    {
        mvwaddch(_data, 0, x, ' ' | A_BOLD);
        mvwaddch(_data, 69, x, ' '| A_BOLD);
    }

    wrefresh(_menu);
    wrefresh(_data);
}

Ncurses::Ncurses()
{
    initscr();
    _menu = newwin(70, 28, 0, 0);
    _data = newwin(70, 100, 0, 28);
    init_visualisation();
    printmenu();
}