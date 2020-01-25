/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetTime.tpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 01:53:38 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CURSESWIDGETTIME_TPP
# define CURSESWIDGETTIME_TPP

#include "ACursesWidget.tpp"

#include <string>
#include <iostream>


template <class T>
class CursesWidgetTime : public ACursesWidget<T>
{
public:
	CursesWidgetTime(WINDOW *win) : ACursesWidget<T>(win){}
	~CursesWidgetTime(void){}

	virtual void displayData(void)
	{
		unsigned int lines;
		unsigned int cols;
		std::time_t time = this->getModName().getData();
		tm *ltm = localtime(&time);

		getmaxyx(this->getWin(), lines, cols);
		unsigned int firstLine = ((lines - 1) / 2);
		unsigned int firstCol =(cols - 25) / 2;

		box(this->getWin(), ACS_VLINE, ACS_HLINE);
		mvwprintw(this->getWin(), firstLine, firstCol, "Time: %02d:%02d:%02d\t%02d/%02d/%d", ltm->tm_hour - 1, ltm->tm_min, ltm->tm_sec, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
	}

private:
	CursesWidgetTime(void);
	CursesWidgetTime(CursesWidgetTime const &rhs);
	CursesWidgetTime &operator=(CursesWidgetTime const &src);

};

#endif
