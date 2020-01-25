/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetInts.tpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 02:06:59 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CURSESWIDGETINTS_TPP
# define CURSESWIDGETINTS_TPP

#include "ACursesWidget.tpp"
#include <vector>

#include <string>
#include <iostream>


template <class T>
class CursesWidgetInts : public ACursesWidget<T>
{
public:
	CursesWidgetInts(void){}
	~CursesWidgetInts(void){}

	virtual void displayData(void)
	{
		std::vector<int> v = this->getModName().getData();

		unsigned int lines = 2 * v.size() + 3;
		unsigned int cols = 40;
		if (lines < 7)
			lines = 7;

		WINDOW *win = subwin(stdscr, lines, cols, this->getTopLeft().y, this->getTopLeft().x);
		box(win, ACS_VLINE, ACS_HLINE);

		unsigned int firstLine = ((lines - v.size()) / 2);
		std::string name = this->getModName().getName();
		unsigned int firstCol = 1 + ((40 - name.size()) / 2);
		mvwprintw(win, 1, firstCol, "%s", name.c_str());
		firstCol = 6;
		for (size_t i = 0; i < v.size(); ++i)
		{
			unsigned squares = (v[i] / 3) - (v[i] % 3) + ((v[i] % 3) >= 2 ? 3 : 0);
			squares = (squares > 30) ? 30 : squares;
			wattron(win, COLOR_PAIR(1));
			for (size_t sq = 0; sq < squares; sq++)
				mvwprintw(win, firstLine, firstCol + sq, " ");
			wattroff(win, COLOR_PAIR(1));
			wattron(win, COLOR_PAIR(2));
			for (size_t sq = squares; sq < 30; sq++)
				mvwprintw(win, firstLine, firstCol + sq, " ");
			wattroff(win, COLOR_PAIR(2));
			firstLine += 2;
		}
		delwin(win);
	}

	virtual coords getSize(void)
	{
		std::vector<int> v = this->getModName().getData();
		coords size;
		size.x = 40;
		size.y = 2 * v.size() + 3;
		if (size.y < 7)
			size.y = 7;
		return (size);
	}

private:
	CursesWidgetInts(CursesWidgetInts const &rhs);
	CursesWidgetInts &operator=(CursesWidgetInts const &src);

};

#endif
