#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay()
{
	Config *cfg = Config::get();
	if (cfg->get()->getDisplay() != Config::DISPLAY_WINDOW)
		return;

	coords window_size(450, 1000);
	this->_window.create(sf::VideoMode(window_size.x, window_size.y), "System Monitor");
	this->_window.setFramerateLimit(10);

	if (!this->font.loadFromFile("src/display/sfml/assets/arial.ttf"))
		throw std::runtime_error("Could not load fonts");
}

SFMLDisplay::~SFMLDisplay()
{
}

AWidget *SFMLDisplay::addWidget(Config::WIDGET_TYPE type)
{
	switch (type)
	{
	case Config::WIDGET_DATE:
		return new SFMLWidgetClock<DateModule>(&this->_window, &this->font);
		break;
	case Config::WIDGET_HOST:
		return new SFMLWidgetText<HostnameModule>(&this->_window, &this->font);
		break;
	case Config::WIDGET_OS:
		return new SFMLWidgetText<OSInfoModule>(&this->_window, &this->font);
		break;
	case Config::WIDGET_RAM:
		return new SFMLWidgetGauge<RamModule>(&this->_window, &this->font);
		break;
	case Config::WIDGET_CPUUSAGE:
		return new SFMLWidgetGauge<CpuUsageModule>(&this->_window, &this->font);
		break;
	case Config::WIDGET_CPUINFO:
		return new SFMLWidgetText<CpuInfoModule>(&this->_window, &this->font);
		break;
	default:
		throw std::runtime_error("Unknown widget type");
		return nullptr;
		break;
	}
}

void SFMLDisplay::render()
{
	Config *cfg = Config::get();
	if (cfg->get()->getDisplay() != Config::DISPLAY_WINDOW)
		return;

	unsigned int current_height = 0;
	std::vector<Config::WIDGET_TYPE> wdg = cfg->getWidgets();

	std::vector<AWidget *> widgets;
	for (unsigned int i = 0; i < wdg.size(); i++)
	{
		current_height += 10;
		AWidget *wd = this->addWidget(wdg[i]);
		wd->setTopLeft(coords(0, current_height));
		current_height += wd->getSize().y;
		wd->setBottomRight(coords(450, current_height));
		widgets.push_back(wd);
	}

	while (this->_window.isOpen())
	{
		this->_window.clear(sf::Color::Black);
		sf::Event event;
		while (this->_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->_window.close();
		}
		for (unsigned int i = 0; i < widgets.size(); ++i)
		{
			widgets[i]->displayData();
		}
		this->_window.display();
	}
	for (unsigned int i = 0; i < widgets.size(); ++i)
		delete widgets[i];
}