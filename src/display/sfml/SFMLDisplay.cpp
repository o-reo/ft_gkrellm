#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay()
{
}

SFMLDisplay::~SFMLDisplay()
{
}

void SFMLDisplay::render()
{
	coords window_size(450, 1200);
	this->_window.create(sf::VideoMode(window_size.x, window_size.y), "System Monitor");
	this->_window.setFramerateLimit(10);

	sf::Font font;
	if (!font.loadFromFile("assets/arial.ttf"))
		throw std::runtime_error("Could not load fonts");
	sf::Text title("System Monitor", font, 24);
	title.setPosition((window_size.x - (14 * 13)) / 2, 10);

	SFMLWidgetText<HostnameModule> hostText(&this->_window, &font);
	hostText.setTopLeft(coords(0, 70));
	hostText.setBottomRight(coords(450, 160));

	SFMLWidgetText<CpuInfoModule> cpuInfo(&this->_window, &font);
	cpuInfo.setTopLeft(coords(0, 170));
	cpuInfo.setBottomRight(coords(450, 285));

	SFMLWidgetText<OSInfoModule> osInfo(&this->_window, &font);
	osInfo.setTopLeft(coords(0, 295));
	osInfo.setBottomRight(coords(450, 460));

	SFMLWidgetGauge<CpuUsageModule> cpuUsage(&this->_window, &font);
	cpuUsage.setTopLeft(coords(0, 470));
	cpuUsage.setBottomRight(coords(450, 645));

	SFMLWidgetGauge<RamModule> ram(&this->_window, &font);
	ram.setTopLeft(coords(0, 655));
	ram.setBottomRight(coords(450, 720));

	while (this->_window.isOpen())
	{
		this->_window.clear(sf::Color::Black);
		sf::Event event;
		while (this->_window.pollEvent(event))
		{
		}
		hostText.displayData();
		cpuInfo.displayData();
		osInfo.displayData();
		cpuUsage.displayData();
		ram.displayData();
		this->_window.draw(title);
		this->_window.display();
	}
}