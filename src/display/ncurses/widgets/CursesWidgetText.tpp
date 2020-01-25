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
	CursesWidgetText(coords tl, coords br) : ACursesWidget<T>(tl, br){}
	~CursesWidgetText(void){}

	virtual void displayData(void)
	{
		unsigned int lines = this->getBottomRight().y - this->getTopLeft().y;
		unsigned int cols = this->getBottomRight().x - this->getTopLeft().x;

		// getmaxyx(this->getWin(), lines, cols);
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();

		unsigned int firstLine = ((lines - v.size()) / 2) + 1;
		// box(this->getWin(), ACS_VLINE, ACS_HLINE);

		std::string name = this->getModName().getName();
		unsigned int firstCol = 1 + ((cols - name.size()) / 2);
		// mvwprintw(this->getWin(), 1, firstCol, "%s", name.c_str());
		for (size_t i = 0; i < v.size(); ++i)
		{
			firstCol = (this->getModName().getName() == "Host Details") ? 10 : 1;
			// mvwprintw(this->getWin(), firstLine, firstCol, "%s : %s", v[i].first.c_str(), v[i].second.c_str());
			firstLine++;
		}
	}

	virtual coords getSize(void)
	{
		std::vector<std::pair<std::string, std::string> > v = this->getModName().getData();
		coords size;
		size.x = 40;
		size.y = v.size() + 2;
		if (size.y < 7)
			size.y = 7;
		return (size);
	}

private:
	CursesWidgetText(void);
	CursesWidgetText(CursesWidgetText const &rhs);
	CursesWidgetText &operator=(CursesWidgetText const &src);

};

#endif
