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

// #include "HostnameModule.hpp"

#include "ACursesWidget.tpp"
#include <vector>

#include <string>
#include <iostream>


template <class T>
class CursesWidgetText : public ACursesWidget<T>
{
public:
	CursesWidgetText(WINDOW *win) : ACursesWidget<T>(win){}
	~CursesWidgetText(void){}

	virtual void displayData(void)
	{
		std::vector<std::string> v = this->getModName().getData();
		unsigned int lines;
		unsigned int cols;

		getmaxyx(this->getWin(), lines, cols);

		unsigned int firstLine = ((lines - v.size()) / 2);
		// std::cout << "First line to write on : " << firstLine << std::endl;
		box(this->getWin(), ACS_VLINE, ACS_HLINE);
		for (size_t i = 0; i < v.size(); ++i)
		{
			// std::cout << v[i] << std::endl;
			unsigned int firstCol = 1 + ((cols - v[i].size()) / 2);
			// std::cout << "First line to write on : " << firstCol << std::endl;
			
			mvwaddstr(this->getWin(), firstLine, firstCol, v[i].c_str());
			firstLine++;
		}
	}

private:
	CursesWidgetText(void);
	CursesWidgetText(CursesWidgetText const &rhs);
	CursesWidgetText &operator=(CursesWidgetText const &src);

};

#endif