/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ACursesWidget.tpp                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 22:25:29 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ACURSESWIDGET_TPP
#define ACURSESWIDGET_TPP

// #include "HostnameModule.hpp"

#include <string>
#include <iostream>

#include "coords.h"

template <class T>
class ACursesWidget
{
public:
	ACursesWidget(coords const tl, coords const br) : _topLeft(tl), _bottomRight(br){}
	~ACursesWidget(void){}

	virtual void displayData(void) = 0;

	void setTopleft(coords const newCoord)
	{
		this->_topLeft = newCoord;
	}

	void setBottomright(coords const newCoord)
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

	T	&getModName(void)
	{
		return (this->_modName);
	}


private:
	ACursesWidget(void);
	ACursesWidget(ACursesWidget const &rhs);
	ACursesWidget &operator=(ACursesWidget const &src);

	T		_modName;
	coords	_topLeft;
	coords	_bottomRight;
};

#endif
