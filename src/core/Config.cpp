#include "Config.hpp"
#include <fstream>
#include <string>

Config *Config::instance = nullptr;

Config::Config() : display(DISPLAY_TERMINAL)
{
	this->parse();
}

Config::~Config()
{
}

Config *Config::get()
{
	if (!Config::instance)
	{
		Config::instance = new Config();
	}
	return Config::instance;
}

void Config::parse()
{
	std::ifstream cfg("config.cfg");
	std::string line;
	while (std::getline(cfg, line))
	{
		if (line == "WINDOW")
			this->display = DISPLAY_WINDOW;
		else if (line == "WIDGET_DATE")
		{
			this->widgets.push_back(WIDGET_DATE);
		}
		else if (line == "WIDGET_OS")
		{
			this->widgets.push_back(WIDGET_OS);
		}
		else if (line == "WIDGET_HOST")
		{
			this->widgets.push_back(WIDGET_HOST);
		}
		else if (line == "WIDGET_RAM")
		{
			this->widgets.push_back(WIDGET_RAM);
		}
		else if (line == "WIDGET_CPUINFO")
		{
			this->widgets.push_back(WIDGET_CPUINFO);
		}
		else if (line == "WIDGET_CPUUSAGE")
		{
			this->widgets.push_back(WIDGET_CPUUSAGE);
		}
	}
}

Config::DISPLAY Config::getDisplay()
{
	return this->display;
}

std::vector<Config::WIDGET_TYPE> Config::getWidgets()
{
	return this->widgets;
}