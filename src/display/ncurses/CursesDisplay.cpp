#include "CursesDisplay.hpp"
#include "IMonitorModule.hpp"


#include "CursesWidgetText.tpp"
#include "CursesWidgetTime.tpp"
#include "CursesWidgetInts.tpp"
// #include "CursesWidgetStr.tpp"

#include "HostnameModule.hpp"
#include "DateModule.hpp"
#include "CpuUsageModule.hpp"
#include "CpuInfoModule.hpp"
#include "OSInfoModule.hpp"
#include "RamModule.hpp"

#include "coords.h"

#include <ncurses.h>


#define FDELAY 1000000 / 10


CursesDisplay::CursesDisplay() {}

CursesDisplay::~CursesDisplay() {}


static long	millisecond_timer(void)
{
	struct timespec		tp;

	clock_gettime(CLOCK_REALTIME, &tp);
	return (long(tp.tv_sec * 1000 + tp.tv_nsec / 1000000) * 1000);
}

void CursesDisplay::render(void)
{
	initscr();
	start_color();

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);

	unsigned long int frameStart;

	curs_set(0);
	noecho();
	clear();
	// nodelay(stdscr, TRUE);

	CursesWidgetText<HostnameModule> mod0(coords(0, 3), coords(40, 10));
	CursesWidgetTime<DateModule> mod1(coords(0, 11), coords(40, 18));
	CursesWidgetInts<CpuUsageModule> mod2(coords(0, 19), coords(40, 30));
	CursesWidgetText<OSInfoModule> mod3(coords(0, 31), coords(40, 40));
	CursesWidgetInts<RamModule> mod4(coords(0, 41), coords(40, 48));
	CursesWidgetText<CpuInfoModule> mod5(coords(0, 49), coords(40, 56));

	while (getch() != 27)
	{
		frameStart = millisecond_timer();
		clear();
		// mod0.displayData();
		mod1.displayData();
		// mod2.displayData();
		// mod3.displayData();
		// mod4.displayData();
		// mod5.displayData();
		refresh();
		while (FDELAY > millisecond_timer() - frameStart)
			;
	}
	endwin();
}
