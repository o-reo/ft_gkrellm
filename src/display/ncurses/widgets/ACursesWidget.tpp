/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ACursesWidget.tpp                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 00:23:58 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ACURSESWIDGET_TPP
#define ACURSESWIDGET_TPP

// #include "HostnameModule.hpp"

#include <string>
#include <iostream>

#include "coords.h"
#include "AWidget.hpp"
#include <ncurses.h>


template <class T>
class ACursesWidget : public AWidget
{
public:
	ACursesWidget(void){}
	virtual ~ACursesWidget(void){}

	void setTopLeft(coords const newCoord)
	{
		this->_topLeft = newCoord;
	}

	void setBottomRight(coords const newCoord)
	{
		this->_bottomRight = newCoord;
	}

	coords getTopLeft(void) const
	{
		return (this->_topLeft);
	}

	coords getBottomRight(void) const
	{
		return (this->_bottomRight);
	}

	virtual void displayData(void) = 0;

	T	&getModName(void)
	{
		return (this->_modName);
	}

	virtual coords getSize() = 0;

private:
	ACursesWidget(ACursesWidget const &rhs);
	ACursesWidget &operator=(ACursesWidget const &src);

	T			_modName;
	coords		_topLeft;
	coords		_bottomRight;
};

#endif
