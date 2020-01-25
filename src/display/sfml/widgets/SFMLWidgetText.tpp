#ifndef SFMLWIDGETTEXT_HPP
#define SFMLWIDGETTEXT_HPP

#include "ASFMLWidget.tpp"
#include "coords.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <class T> class SFMLWidgetText : public ASFMLWidget<T>
{
  public:
	SFMLWidgetText(sf::RenderWindow *win, sf::Font *font) : ASFMLWidget<T>(win), _font(font)
	{
	}
	~SFMLWidgetText(void)
	{
	}

	virtual void displayData(void)
	{
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();
		coords avail(this->getBottomRight().x - this->getTopLeft().x, this->getBottomRight().y - this->getTopLeft().y);

		// Box
		sf::RectangleShape border(sf::Vector2f(avail.x - 6, avail.y - 32));
		border.setPosition(this->getTopLeft().x + 3, this->getTopLeft().y + 32);
		border.setFillColor(sf::Color::Transparent);
		border.setOutlineColor(sf::Color::White);
		border.setOutlineThickness(1.0f);
		this->getWin()->draw(border);

		this->_texts.clear();
		this->_texts.push_back(sf::Text(this->getModName().getName(), *(this->_font), 24));
		this->_texts.back().setPosition((avail.x - 12 * this->getModName().getName().size()) / 2, this->getTopLeft().y);
		this->getWin()->draw(this->_texts.back());

		for (unsigned int i = 0; i < v.size(); ++i)
		{
			// Label
			this->_texts.push_back(sf::Text(v[i].first, *(this->_font), 22));
			this->_texts.back().setPosition(5, 35 + this->getTopLeft().y + 25 * i);
			this->getWin()->draw(this->_texts.back());

			// Value
			this->_texts.push_back(sf::Text(v[i].second, *(this->_font), 22));
			this->_texts.back().setPosition(125, 35 + this->getTopLeft().y + 25 * i);
			this->getWin()->draw(this->_texts.back());
		}
	}

	virtual coords getSize()
	{
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();
		coords cds;
		cds.y = 35 + 25 * v.size();
		cds.x = this->getBottomRight().x - this->getTopLeft().x;
		return cds;
	}

  private:
	SFMLWidgetText(void);
	SFMLWidgetText(SFMLWidgetText const &rhs);
	SFMLWidgetText &operator=(SFMLWidgetText const &src);
	std::vector<sf::Text> _texts;
	sf::Font *_font;
};

#endif
