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
	Config *cfg = Config::get();
	if (cfg->get()->getDisplay() != Config::DISPLAY_TERMINAL)
		return;
	initscr();
	start_color();

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);

	unsigned long int frameStart;

	curs_set(0);
	noecho();
	clear();
	nodelay(stdscr, TRUE);

	/*CursesWidgetText<HostnameModule> mod0(coords(0, 3), coords(40, 10));
	CursesWidgetTime<DateModule> mod1(coords(0, 11), coords(40, 18));
	CursesWidgetInts<CpuUsageModule> mod2(coords(0, 19), coords(40, 30));
	CursesWidgetText<OSInfoModule> mod3(coords(0, 31), coords(40, 40));
	CursesWidgetInts<RamModule> mod4(coords(0, 41), coords(40, 48));
	CursesWidgetText<CpuInfoModule> mod5(coords(0, 49), coords(40, 56));
*/

	unsigned int current_height = 0;
	std::vector<Config::WIDGET_TYPE> wdg = cfg->getWidgets();

	std::vector<AWidget *> widgets;
	for (unsigned int i = 0; i < wdg.size(); i++)
	{
		current_height += 1;
		AWidget *wd = this->addWidget(wdg[i]);
		wd->setTopLeft(coords(0, current_height));
		current_height += wd->getSize().y;
		wd->setBottomRight(coords(40, current_height));
		widgets.push_back(wd);
	}

	while (getch() != 27)
	{
		frameStart = millisecond_timer();
		clear();
		for (size_t iter = 0; iter < widgets.size(); ++iter)
			widgets[iter]->displayData();
		refresh();
		while (FDELAY > millisecond_timer() - frameStart)
			;
	}
	endwin();
	for (unsigned int i = 0; i < widgets.size(); ++i)
		delete widgets[i];
}

AWidget *CursesDisplay::addWidget(Config::WIDGET_TYPE type)
{
	switch (type)
	{
	case Config::WIDGET_DATE:
		return new CursesWidgetTime<DateModule>();
		break;
	case Config::WIDGET_HOST:
		return new CursesWidgetText<HostnameModule>();
		break;
	case Config::WIDGET_OS:
		return new CursesWidgetText<OSInfoModule>();
		break;
	case Config::WIDGET_RAM:
		return new CursesWidgetInts<RamModule>();
		break;
	case Config::WIDGET_CPUUSAGE:
		return new CursesWidgetInts<CpuUsageModule>();
		break;
	case Config::WIDGET_CPUINFO:
		return new CursesWidgetText<CpuInfoModule>();
		break;
	default:
		throw std::runtime_error("Unknown widget type");
		return nullptr;
		break;
	}
}
