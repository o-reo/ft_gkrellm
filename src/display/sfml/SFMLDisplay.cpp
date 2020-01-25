#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay()
{
}

SFMLDisplay::~SFMLDisplay()
{
}

void SFMLDisplay::render()
{
	coords window_size(400, 1200);

	sf::Font font;
	if (!font.loadFromFile("assets/arial.ttf"))
		throw std::runtime_error("Could not load fonts");
	sf::Text title("System Monitor", font, 24);
	title.setPosition((window_size.x - (14 * 13)) / 2, 10);

	SFMLWidgetText<HostnameModule> hostText(&this->_window, &font);
	
	
	this->_window.create(sf::VideoMode(window_size.x, window_size.y), "System Monitor",
						 sf::Style::Close | sf::Style::Titlebar);
	this->_window.setFramerateLimit(10);

	while (this->_window.isOpen())
	{
		this->_window.clear(sf::Color::Black);
		sf::Event event;
		while (this->_window.pollEvent(event))
		{
		}
		hostText.displayData();
		this->_window.draw(title);
		this->_window.display();
	}
}