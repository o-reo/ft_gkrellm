#ifndef SFMLWIDGETCLOCK_HPP
#define SFMLWIDGETCLOCK_HPP

#include "ASFMLWidget.tpp"
#include <vector>

#include <iostream>
#include <string>
#include <utility>

template <class T> class SFMLWidgetClock : public ASFMLWidget<T>
{
  public:
	SFMLWidgetClock(sf::RenderWindow *win, sf::Font *font) : ASFMLWidget<T>(win), _font(font)
	{
	}
	~SFMLWidgetClock(void)
	{
	}

	virtual void displayData(void)
	{
		coords avail(this->getBottomRight().x - this->getTopLeft().x, this->getBottomRight().y - this->getTopLeft().y);
		
		// Box
		sf::RectangleShape border(sf::Vector2f(avail.x - 6, avail.y - 32));
		border.setPosition(this->getTopLeft().x + 3, this->getTopLeft().y + 32);
		border.setFillColor(sf::Color::Transparent);
		border.setOutlineColor(sf::Color::White);
		border.setOutlineThickness(1.0f);
		this->getWin()->draw(border);
		
		sf::Text title(this->getModName().getName(), *(this->_font), 24);
		title.setPosition((avail.x - 12 * this->getModName().getName().size()) / 2, this->getTopLeft().y);
		this->getWin()->draw(title);

		std::time_t v = this->getModName().getData();

		sf::Text clock(std::asctime(std::localtime(&v)), *(this->_font), 22);
		clock.setPosition((avail.x - 250) / 2, 35 + this->getTopLeft().y);
		this->getWin()->draw(clock);
	}

  private:
	SFMLWidgetClock(void);
	SFMLWidgetClock(SFMLWidgetClock const &rhs);
	SFMLWidgetClock &operator=(SFMLWidgetClock const &src);
	sf::Font *_font;
};

#endif
