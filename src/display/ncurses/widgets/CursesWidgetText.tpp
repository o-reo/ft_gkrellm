/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetText.tpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 01:12:02 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CURSESWIDGETTEXT_TPP
# define CURSESWIDGETTEXT_TPP


#include "ACursesWidget.tpp"
#include <vector>

#include <string>
#include <iostream>


template <class T>
class CursesWidgetText : public ACursesWidget<T>
{
public:
	CursesWidgetText(void){}
	~CursesWidgetText(void){}

	virtual void displayData(void)
	{
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();
		unsigned int lines = v.size() + 4;
		unsigned int cols = 40;
		if (lines < 7)
			lines = 7;

		WINDOW *win = subwin(stdscr, lines, cols, this->getTopLeft().y, this->getTopLeft().x);
		box(win, ACS_VLINE, ACS_HLINE);

		unsigned int firstLine = ((lines - v.size()) / 2) + 1;

		std::string name = this->getModName().getName();
		unsigned int firstCol = 1 + ((cols - name.size()) / 2);
		mvwprintw(win, 1, firstCol, "%s", name.c_str());
		for (size_t i = 0; i < v.size(); ++i)
		{
			firstCol = (this->getModName().getName() == "Host Details") ? 10 : 1;
			mvwprintw(win, firstLine, firstCol, "%s : %s", v[i].first.c_str(), v[i].second.c_str());
			firstLine++;
		}
		delwin(win);
	}

	virtual coords getSize(void)
	{
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();
		coords size;
		size.x = 40;
		size.y = v.size() + 4;
		if (size.y < 7)
			size.y = 7;
		return (size);
	}

private:
	CursesWidgetText(CursesWidgetText const &rhs);
	CursesWidgetText &operator=(CursesWidgetText const &src);

};

#endif
