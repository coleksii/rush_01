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
	keypad(_data, TRUE);
	keypad(stdscr, TRUE);
	nodelay(_menu, TRUE);
	nodelay(stdscr, TRUE);
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


void Ncurses::pluginUserInfo(){
	wattron(_data, COLOR_PAIR(3));
	mvwprintw(_menu, 1, 1, "%s", "plugin User Info");
	mvwprintw(_data, 2, 4, "Username: %s", user.getUser());
	mvwprintw(_data, 3, 4, "Hostname: %s", user.getHost());
	wattrset(_data, A_NORMAL);
}

void Ncurses::pluginMemory(){
	mvwprintw(_menu, 1, 1, "%s", "plugin Memory");
	mvwprintw(_data, 5, 4, "Free memory: %lld kb     ", ram.getFreeMemory() / 1024);
	mvwprintw(_data, 6, 4, "Used memory: %lld kb     ", ram.getUsedMemore() / 1024);
	ram.reload();

}

void Ncurses::pluginCPU(){
	mvwprintw(_menu, 1, 1, "%s", "plugin CPU");
	mvwprintw(_data, 20, 4, "CPU used: %.0f%%   ", cpu.get_cpu() * 100);
	mvwprintw(_data, 21, 4, "CPU free: %.0f%%   ", cpu.get_cpu_free() * 100);
	cpu.reload();

}

void Ncurses::pluginOS(){
	mvwprintw(_menu, 1, 1, "%s", "plugin OS");
	mvwprintw(_data, 7, 4, "%s", os.get_buff());
}

void Ncurses::initplugin(){
	this->f[0] = &Ncurses::pluginUserInfo;
	this->f[1] = &Ncurses::pluginMemory;
	this->f[2] = &Ncurses::pluginOS;
	this->f[3] = &Ncurses::pluginCPU;
}

void Ncurses::allplugins()
{
	numb = 1;
	int ch = 1;
	initplugin();
	while (ch != 27)
	{
		werase(_data);
		werase(_menu);
		(this->*f[numb])();
		mvwprintw(_data, 1, 1, "Free memory: %d     ", numb);
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
	wattrset(_menu, A_NORMAL);
	wattrset(_data, A_NORMAL);
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
