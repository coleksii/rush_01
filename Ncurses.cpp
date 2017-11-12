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
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
}

Ncurses::~Ncurses()
{
	endwin();
}


void Ncurses::pluginUserInfo(){
	wattron(_data, COLOR_PAIR(3));
	mvwprintw(_data, 2, 4, "Username: %s", user.getUser());
	mvwprintw(_data, 3, 4, "Hostname: %s", user.getHost());
    mvwprintw(_data, 4, 4, "Date: %d/%d/%d", time.getYear() + 1900, time.getMonth() + 1, time.getDay());
    mvwprintw(_data, 5, 4, "Hours:  %d", time.getHour());
    mvwprintw(_data, 6, 4, "Min:    %d", time.getMin());
    mvwprintw(_data, 7, 4, "Sec:    %d", time.getSec());
	wattrset(_data, A_NORMAL);
}

void Ncurses::printGr(int y, double l){
//    mvwprintw(_data, y, 45, "%f", l);
    mvwprintw(_data, y, 40, "[");
    for (int i = 0; i < l && i < 90; i++)
        mvwprintw(_data, y, 42 + i, "|");
    mvwprintw(_data, y, 90, "]");
}

void Ncurses::graphickModeMemory(){
    double l;
    l = static_cast<double>(ram.getVirt_freeMemory())/ram.getPhysical_memory() * 100;
    l *= 2;
    wattron(_data, COLOR_PAIR(5));
    printGr(2, l);
    l = static_cast<double>(ram.getVirt_UsedMemory())/ram.getPhysical_memory() * 100;
    l /= 2;
    printGr(3, l);
    l = static_cast<double>(ram.getPhys_Used_memory())/ram.getPhysical_memory() * 100;
    l *= 20000;
    printGr(5, l);
    l = static_cast<double>(ram.getPhys_Unused_memory())/ram.getPhysical_memory() * 100;
    l *= 2000000;
    printGr(6, l);
    l = static_cast<double>(ram.getPhys_Wired_memory())/ram.getPhysical_memory() * 100;
    l *= 200000;
    printGr(7, l);
    wattrset(_data, A_NORMAL);
}

void Ncurses::pluginMemory(){
    mvwprintw(_data, 2, 4, "Virt Free memory: %ld\tkb     ", ram.getVirt_freeMemory() / 1024);
    mvwprintw(_data, 3, 4, "Virt Used memory: %ld\tkb     ", ram.getVirt_UsedMemory() / 1024);
    mvwprintw(_data, 4, 4, "Physical memory:  %llu\tkb     ", ram.getPhysical_memory() / 1024);
    mvwprintw(_data, 5, 4, "Physical used memory:    %4ld      ", ram.getPhys_Used_memory());
    mvwprintw(_data, 6, 4, "Physical unused memory:  %4ld      ", ram.getPhys_Unused_memory());
    mvwprintw(_data, 7, 4, "Physical wired memory:   %4ld      ", ram.getPhys_Wired_memory());
    graphickModeMemory();
}

void Ncurses::pluginNetwork(){
    mvwprintw(_data, 2, 4, "Network out %s     ", net.getOut());
    mvwprintw(_data, 3, 4, "Newtork in %s      ", net.getIn());
}

void Ncurses::pluginCPU(){
    mvwprintw(_data, 2, 4, "CPU name: %s   ", cpu.get_cpu_name());
    mvwprintw(_data, 3, 4, "CPU cores: %d   ", cpu.get_cores());
    mvwprintw(_data, 4, 4, "CPU used: %.0f%%   ", cpu.get_cpu() * 100);
    mvwprintw(_data, 5, 4, "CPU free: %.0f%%   ", cpu.get_cpu_free() * 100);
    wattron(_data, COLOR_PAIR(6));
    double l;
    l = static_cast<double>(cpu.get_cpu())/1 * 100;
    l /= 2;
    printGr(4, l);
    l = static_cast<double>(cpu.get_cpu_free())/1 * 100;
    l /= 2;
    printGr(5, l);
    wattrset(_data, A_NORMAL);

}

void Ncurses::pluginOS(){
	mvwprintw(_data, 2, 4, "%s", os.get_buff());
}

void Ncurses::initplugin(){
	this->f[0] = &Ncurses::pluginUserInfo;
	this->f[1] = &Ncurses::pluginMemory;
	this->f[2] = &Ncurses::pluginOS;
	this->f[3] = &Ncurses::pluginCPU;
    this->f[4] = &Ncurses::pluginNetwork;
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
        refresh();
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
		Ncurses::numb = 4;
	else if (numb > 4)
		Ncurses::numb = 0;
	else
		Ncurses::numb = numb;
}


void Ncurses::initStrMenu() {
    men[0] = const_cast<char *>("User info");
    men[1] = const_cast<char *>("RAM");
    men[2] = const_cast<char *>("OS Info");
    men[3] = const_cast<char *>("CPU");
    men[4] = const_cast<char *>("Network");
}


void Ncurses::printLeft() {
    int x = 1;
    int y = 1;
    mvwprintw(_menu, y, x, "__________________________");
    y += 4;
    for (int i = 0; i < 5; i++) {
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
	refresh();
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

Ncurses::Ncurses(Ncurses &nc) {
    this->user = nc.user;
    this->cpu = nc.cpu;
    this->os = nc.os;
    this->ram = nc.ram;
    this->time = nc.time;
    this->_menu = nc._menu;
    this->numb = nc.numb;

}

Ncurses const &Ncurses::operator=(Ncurses &nc) {
    this->user = nc.user;
    this->cpu = nc.cpu;
    this->os = nc.os;
    this->ram = nc.ram;
    this->time = nc.time;
    this->_menu = nc._menu;
    this->numb = nc.numb;
    return *this;
}
