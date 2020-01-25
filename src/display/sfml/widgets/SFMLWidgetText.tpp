#ifndef SFMLWIDGETTEXT_HPP
#define SFMLWIDGETTEXT_HPP

#include "ASFMLWidget.tpp"
#include <vector>

#include <iostream>
#include <string>

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
		std::vector<std::string> v = this->getModName().getData();
		unsigned int height = v.size();
		this->_texts.clear();
		for (int i = 0; i < v.size(); ++i)
		{
			this->_texts.push_back(sf::Text(v[i], *(this->_font), 24));
			unsigned int w = v[i].size();
			unsigned int w_avail = this->getBottomRight().x - this->getTopLeft().x;
			this->_texts.back().setPosition(80, 150 + 20 * i);
			std::cout << v[i] << std::endl;
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
