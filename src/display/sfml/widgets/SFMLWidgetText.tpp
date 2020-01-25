#ifndef SFMLWIDGETTEXT_HPP
#define SFMLWIDGETTEXT_HPP

#include "ASFMLWidget.tpp"
#include <vector>

#include <iostream>
#include <string>
#include <utility>

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
		// coords avail(this->getBottomRight().x - this->getTopLeft().x, this->getBottomRight().y - this->getTopLeft().y);
		
		this->_texts.clear();
		this->_texts.push_back(sf::Text(this->getModName().getName(), *(this->_font), 24));
		for (unsigned int i = 0; i < v.size(); ++i)
		{
			// Label
			this->_texts.push_back(sf::Text(v[i].first, *(this->_font), 22));
			this->_texts.back().setPosition(5, this->getTopLeft().y + 25 * i);
			this->getWin()->draw(this->_texts.back());

			// Value
			this->_texts.push_back(sf::Text(v[i].second, *(this->_font), 22));
			std::cout << v[i].second << std::endl;
			this->_texts.back().setPosition(80, this->getTopLeft().y + 25 * i);
			this->getWin()->draw(this->_texts.back());
		}
	}

  private:
	SFMLWidgetText(void);
	SFMLWidgetText(SFMLWidgetText const &rhs);
	SFMLWidgetText &operator=(SFMLWidgetText const &src);
	std::vector<sf::Text> _texts;
	sf::Font *_font;
};

#endif
