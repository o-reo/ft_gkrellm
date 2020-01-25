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

#include <ncurses.h>


template <class T>
class ACursesWidget : public AWidget
{
public:
	ACursesWidget(WINDOW *win) : _win(win){}
	~ACursesWidget(void){free(this->_win);}

	virtual void displayData(void) = 0;

	void setTopleft(coords const newCoord)
	{
		this->_topLeft = newCoord;
	}

	void setBottomright(coords const newCoord)
	{
		this->_bottomRight = newCoord;
	}

	// coords getTopLeft(void) const
	// {
	// 	return (this->_topLeft);
	// }

	// coords getBottomRight(void) const
	// {
	// 	return ();
	// }

	T	&getModName(void)
	{
		return (this->_modName);
	}

	WINDOW *getWin(void)
	{
		return (this->_win);
	}


private:
	ACursesWidget(void);
	ACursesWidget(ACursesWidget const &rhs);
	ACursesWidget &operator=(ACursesWidget const &src);

	T		_modName;
	WINDOW	*_win;
};

#endif
