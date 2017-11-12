//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#include "Ncurses.hpp"
#include <zconf.h>
#include <ctime>

void Ncurses::init_visualisation() const
{
	noecho();
	//    cbreak();
	signal(SIGWINCH, nullptr);
	curs_set(0);
	start_color();
	keypad(_menu, true);
	keypad(_data, true);
	keypad(stdscr, true);
	nodelay(_menu, true);
	nodelay(stdscr, true);
	init_pair(1, COLOR_BLACK, 8);//for margins of menu
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);//for menu text
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
}

Ncurses::~Ncurses()
{
	endwin();
}

void Ncurses::printmenudata() const
{
	wattron(_menu, COLOR_PAIR(2));

}


void Ncurses::pluginUserInfo(){
	wattron(_data, COLOR_PAIR(3));
	mvwprintw(_data, 2, 4, "Username: %s", user.getUser());
	mvwprintw(_data, 3, 4, "Hostname: %s", user.getHost());
	wattrset(_data, A_NORMAL);
}

void Ncurses::pluginMemory(){
	mvwprintw(_data, 2, 4, "Free memory: %lld kb     ", ram.getFreeMemory() / 1024);
	mvwprintw(_data, 3, 4, "Used memory: %lld kb     ", ram.getUsedMemore() / 1024);


}

void Ncurses::pluginCPU(){
	mvwprintw(_data, 2, 4, "CPU used: %.0f%%   ", cpu.get_cpu() * 100);
	mvwprintw(_data, 3, 4, "CPU free: %.0f%%   ", cpu.get_cpu_free() * 100);


}

void Ncurses::pluginOS(){
	mvwprintw(_data, 2, 4, "%s", os.get_buff());
}

void Ncurses::initplugin(){
	this->f[0] = &Ncurses::pluginUserInfo;
	this->f[1] = &Ncurses::pluginMemory;
	this->f[2] = &Ncurses::pluginOS;
	this->f[3] = &Ncurses::pluginCPU;
}

void Ncurses::reload(){
    cpu.reload();
    ram.reload();
}

void Ncurses::allplugins()
{
	int ch = 1;
	initplugin();
	while (ch != 27)
	{
		werase(_data);
		werase(_menu);
        (this->*f[numb])();
        ch = getch();
		if (ch == 258) {
			setNumb(numb + 1);
		}
		if (ch == 259) {
			setNumb(numb - 1);
		}
		printmenu();
		wrefresh(_data);
		wrefresh(_menu);
		usleep(100000);
        if (clock() % 1000000000000000000)
            reload();
	}
}

int Ncurses::getNumb() const {
	return numb;
}

void Ncurses::setNumb(int numb) {
	if (numb < 0)
		Ncurses::numb = 3;
	else if (numb > 3)
		Ncurses::numb = 0;
	else
		Ncurses::numb = numb;
}


void Ncurses::initStrMenu() {
    men[0] = const_cast<char *>("User info");
    men[1] = const_cast<char *>("RAM");
    men[2] = const_cast<char *>("OS Info");
    men[3] = const_cast<char *>("CPU");
}


void Ncurses::printLeft() {
    int x = 1;
    int y = 1;
    mvwprintw(_menu, y, x, "__________________________");
    y += 4;
    for (int i = 0; i < 4; i++) {
        mvwprintw(_menu, y - 2, x, "%s", men[i]);
        mvwprintw(_menu, y, x, "__________________________");
        y += 4;
    }
    wattron(_menu, COLOR_PAIR(4));
    y = numb * 4 + 1;
    mvwprintw(_menu, y+1, x, "                          ");
    mvwprintw(_menu, y+2, x, "                          ");
    mvwprintw(_menu, y+3, x, "                          ");
    mvwprintw(_menu, y+4, x, "__________________________");
    mvwprintw(_menu, y + 2, x, "%s", men[numb]);
    wattrset(_menu, A_NORMAL);
}

void Ncurses::printmenu()
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
	wattrset(_menu, A_NORMAL);
    wattrset(_data, A_NORMAL);
    printLeft();
    wrefresh(_menu);
	wrefresh(_data);
}

Ncurses::Ncurses()
{
    numb = 0;
	initscr();
    initStrMenu();
	_menu = newwin(70, 28, 0, 0);
	_data = newwin(70, 100, 0, 28);
	init_visualisation();
	printmenu();
}
