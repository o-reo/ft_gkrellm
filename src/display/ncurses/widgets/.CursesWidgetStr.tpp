/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetStr.tpp                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 02:15:37 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CURSESWIDGETSTR_TPP
# define CURSESWIDGETSTR_TPP

// #include "HostnameModule.hpp"

#include "ACursesWidget.tpp"
#include <vector>

#include <string>
#include <iostream>


template <class T>
class CursesWidgetStr : public ACursesWidget<T>
{
public:
	CursesWidgetStr(coords tl, coords br) : _topleft(tl), _bottomright(br){}
	~CursesWidgetStr(void){}

	virtual void displayData(void)
	{
		std::string v = this->getModName().getData();
		unsigned int lines;
		unsigned int cols;

		getmaxyx(this->getWin(), lines, cols);

		// unsigned int firstLine = ((lines - v.size()) / 2);
		// unsigned int firstCol = 1 + ((cols - v.size()) / 2);
		box(this->getWin(), ACS_VLINE, ACS_HLINE);
		mvwprintw(this->getWin(), 1, 1, "%s", v.c_str());
	}

private:
	CursesWidgetStr(void);
	CursesWidgetStr(CursesWidgetStr const &rhs);
	CursesWidgetStr &operator=(CursesWidgetStr const &src);

};

#endif
