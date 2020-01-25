#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <vector>

struct Config
{
  public:
	enum DISPLAY
	{
		DISPLAY_TERMINAL,
		DISPLAY_WINDOW
	};
	enum WIDGET_TYPE
	{
		WIDGET_DATE,
		WIDGET_OS,
		WIDGET_HOST,
		WIDGET_RAM,
		WIDGET_CPUINFO,
		WIDGET_CPUUSAGE
	};
	~Config();
	static Config *get();
	std::vector<WIDGET_TYPE> getWidgets();
	void parse();
	DISPLAY getDisplay();

  private:
	static Config *instance;
	Config();
	Config(Config const &src);
	Config &operator=(Config const &src);
	
	DISPLAY display;
	std::vector<WIDGET_TYPE> widgets;
};

#endif