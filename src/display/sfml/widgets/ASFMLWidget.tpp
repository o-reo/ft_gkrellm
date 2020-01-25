#ifndef ASFMLWIDGET_HPP
#define ASFMLWIDGET_HPP

#include "coords.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

template <class T> class ASFMLWidget
{
  public:
	ASFMLWidget(sf::RenderWindow *win) : _win(win)
	{
	}
	~ASFMLWidget(void)
	{
	}

	virtual void displayData(void) = 0;

	void setTopLeft(coords const newCoord)
	{
		this->_topleft = newCoord;
	}

	void setBottomRight(coords const newCoord)
	{
		this->_bottomright = newCoord;
	}

	coords getTopLeft(void) const
	{
		return (this->_topleft);
	}

	coords getBottomRight(void) const
	{
		return (this->_bottomright);
	}

	T &getModName(void)
	{
		return (this->_modName);
	}

	sf::RenderWindow *getWin(void)
	{
		return (this->_win);
	}

  private:
	ASFMLWidget(void);
	ASFMLWidget(ASFMLWidget const &rhs);
	ASFMLWidget &operator=(ASFMLWidget const &src);

	T _modName;
	sf::RenderWindow *_win;
	coords _topleft;
	coords _bottomright;
};

#endif
