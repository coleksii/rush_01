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
    void allplugins();
	int getNumb() const;
	void setNumb(int numb);
	void pluginUserInfo();
	void pluginMemory();
	void pluginCPU();
	void initplugin();
	void pluginOS();
private:
	UserInfo user;
	OSInfo os;
	CPU cpu;
	RamMemory ram;

	WINDOW *_menu;
    WINDOW *_data;
	int		numb;
	void ((Ncurses::*f[5]))();
    void init_visualisation() const;
    void printmenu() const;
    void printmenudata() const;
};


#endif //RUSH01_NCURSES_HPP
