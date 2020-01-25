#ifndef SFMLWIDGETGAUGE_HPP
#define SFMLWIDGETGAUGE_HPP

#include "ASFMLWidget.tpp"
#include <vector>

#include <iostream>
#include <string>
#include <utility>

template <class T> class SFMLWidgetGauge : public ASFMLWidget<T>
{
  public:
	SFMLWidgetGauge(sf::RenderWindow *win, sf::Font *font)
		: ASFMLWidget<T>(win), _font(font), _title(sf::Text(this->getModName().getName(), *font, 24))
	{
	}
	~SFMLWidgetGauge(void)
	{
	}

	virtual void displayData(void)
	{
		std::vector<int> v = this->getModName().getData();

		coords avail(this->getBottomRight().x - this->getTopLeft().x, this->getBottomRight().y - this->getTopLeft().y);

		this->_title.setPosition((avail.x - 12 * this->getModName().getName().size()) / 2, this->getTopLeft().y);
		this->getWin()->draw(this->_title);

		for (unsigned int i = 0; i < v.size(); ++i)
		{
			sf::RectangleShape gborder(sf::Vector2f(avail.x - 16, 25));
			gborder.setFillColor(sf::Color::Transparent);
			gborder.setOutlineColor(sf::Color::White);
			gborder.setOutlineThickness(1.0f);
			gborder.setPosition(this->getTopLeft().x + 8, this->getTopLeft().y + 35 + 36 * i);
			this->getWin()->draw(gborder);

			sf::RectangleShape gvalue(sf::Vector2f(((avail.x - 16) * v[i]) / 100.0f, 25));
			gvalue.setFillColor(sf::Color::White);
			gvalue.setPosition(this->getTopLeft().x + 8, this->getTopLeft().y + 35 + 36 * i);
			this->getWin()->draw(gvalue);
		}
	}

	virtual coords getSize()
	{
		std::vector<int> v = this->getModName().getData();

		coords cds;
		cds.y = 35 + 36 * v.size();
		cds.x = this->getBottomRight().x - this->getTopLeft().x;
		return cds;
	}

  private:
	SFMLWidgetGauge(void);
	SFMLWidgetGauge(SFMLWidgetGauge const &rhs);
	SFMLWidgetGauge &operator=(SFMLWidgetGauge const &src);
	sf::Font *_font;
	sf::Text _title;
};

#endif
