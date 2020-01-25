/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 19:09:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 02:14:00 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

// #include "Logger.hpp"
// #include "Monitor.hpp"

#include "CursesWidgetText.tpp"
#include "CursesWidgetTime.tpp"
#include "CursesWidgetInts.tpp"
#include "CursesWidgetStr.tpp"

#include "HostnameModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "OSInfoModule.hpp"

#include "coords.h"

#include <ncurses.h>

int main(void)
{
	initscr();

	curs_set(0);
	noecho();
	clear();

	std::vector<WINDOW*> v;

	v.push_back(subwin(stdscr, 7, 40, 0, 0));
	v.push_back(subwin(stdscr, 7, 40, 7, 0));
	v.push_back(subwin(stdscr, 7, 40, 14, 0));
	v.push_back(subwin(stdscr, 7, 40, 21, 0));

	CursesWidgetText<HostnameModule> mod(v[0]);
	CursesWidgetTime<DateModule> mod2(v[1]);
	CursesWidgetInts<CpuModule> mod3(v[2]);
	CursesWidgetStr<OSInfoModule> mod4(v[3]);

	mod.displayData();
	mod2.displayData();
	mod3.displayData();
	mod4.displayData();
	getch();
	endwin();
	return (0);
}
