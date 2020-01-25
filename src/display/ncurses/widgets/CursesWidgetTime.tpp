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
	CursesWidgetTime(coords tl, coords br) : ACursesWidget<T>(tl, br){}
	~CursesWidgetTime(void){}

	virtual void displayData(void)
	{
		unsigned int lines = this->getBottomRight().y - this->getTopLeft().y;
		unsigned int cols = this->getBottomRight().x - this->getTopLeft().x;
		
		WINDOW *win = subwin(stdscr, lines, cols, this->getTopLeft().y, this->getTopLeft().x);
		box(win, ACS_VLINE, ACS_HLINE);
		std::time_t time = this->getModName().getData();
		tm *ltm = localtime(&time);

		// getmaxyx(this->getWin(), lines, cols);
		unsigned int firstLine = ((lines - 1) / 2);
		unsigned int firstCol =(cols - 25) / 2;

		// mvwprintw(win, 0, 0, "%u %u %u", this->getTopLeft().x, cols, firstCol);
		mvwprintw(win, firstLine, firstCol, "Time: %02d:%02d:%02d\t%02d/%02d/%d", ltm->tm_hour - 1, ltm->tm_min, ltm->tm_sec, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
		delwin(win);
	}

	virtual coords getSize(void)
	{
		return (coords(40, 7));
	}

private:
	CursesWidgetTime(void);
	CursesWidgetTime(CursesWidgetTime const &rhs);
	CursesWidgetTime &operator=(CursesWidgetTime const &src);

};

#endif
