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
	CursesWidgetInts(WINDOW *win) : ACursesWidget<T>(win){}
	~CursesWidgetInts(void){}

	virtual void displayData(void)
	{
		std::vector<int> v = this->getModName().getData();
		unsigned int lines;
		unsigned int cols;

		getmaxyx(this->getWin(), lines, cols);

		unsigned int firstLine = ((lines - v.size()) / 2);
		box(this->getWin(), ACS_VLINE, ACS_HLINE);
		for (size_t i = 0; i < v.size(); ++i)
		{
			unsigned int firstCol = 1 + ((cols - std::to_string(v[i]).size()) / 2);
			mvwprintw(this->getWin(), firstLine, firstCol, "%d %%", v[i]);
			firstLine++;
		}
	}

private:
	CursesWidgetInts(void);
	CursesWidgetInts(CursesWidgetInts const &rhs);
	CursesWidgetInts &operator=(CursesWidgetInts const &src);

};

#endif
