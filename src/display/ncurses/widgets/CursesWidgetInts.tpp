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
	CursesWidgetInts(coords tl, coords br) : ACursesWidget<T>(tl, br){}
	~CursesWidgetInts(void){}

	virtual void displayData(void)
	{

		unsigned int lines = this->getBottomRight().y - this->getTopLeft().y;
		unsigned int cols = this->getBottomRight().x - this->getTopLeft().x;
		WINDOW *win = subwin(stdscr, lines, cols, this->getTopLeft().y, this->getTopLeft().x);
		box(win, ACS_VLINE, ACS_HLINE);
(void)cols;
		std::vector<int> v = this->getModName().getData();

		unsigned int firstLine = ((lines - v.size()) / 2);
		std::string name = this->getModName().getName();
		unsigned int firstCol = 1 + ((40 - name.size()) / 2);
		// mvwprintw(this->getWin(), 1, firstCol, "%s", name.c_str());
		firstCol = 1 + ((40 - 30) / 2);
		for (size_t i = 0; i < v.size(); ++i)
		{
			unsigned squares = v[i] - (v[i] % 3) + ((v[i] % 3) >= 2 ? 3 : 0);
			squares = (squares > 30) ? 30 : squares;
			// wattron(this->getWin(), COLOR_PAIR(1));
				// for (size_t sq = 0; sq < squares; sq++)
					// mvwprintw(this->getWin(), firstLine, firstCol + sq, " ");
			// wattron(this->getWin(), COLOR_PAIR(2));
				// for (size_t sq = squares; sq < 30; sq++)
					// mvwprintw(this->getWin(), firstLine, firstCol + sq, " ");
			// wattroff(this->getWin(), COLOR_PAIR(1));
			firstLine += 2;
		}
	}

	virtual coords getSize(void)
	{
		std::vector<int> v = this->getModName().getData();
		coords size;
		size.x = 40;
		size.y = 2 * v.size() + 1;
		if (size.y < 7)
			size.y = 7;
		return (size);
	}

private:
	CursesWidgetInts(void);
	CursesWidgetInts(CursesWidgetInts const &rhs);
	CursesWidgetInts &operator=(CursesWidgetInts const &src);

};

#endif
