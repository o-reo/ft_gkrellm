/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetText.tpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 22:20:05 by bnoyer      ###    #+. /#+    ###.fr     */
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
	CursesWidgetText(coords const tl, coords const br) : ACursesWidget<T>(tl, br){}
	~CursesWidgetText(void){}

	virtual void displayData(void)
	{
		std::vector<std::string> v = this->getModName().getData();
		unsigned int lines = this->getBottomRight().y - this->getTopLeft().y;
		unsigned int cols = this->getBottomRight().x - this->getTopLeft().x;

		unsigned int firstLine = this->getTopLeft().y + ((lines - v.size()) / 2);
		std::cout << "First line to write on : " << firstLine << std::endl;
		for (size_t i = 0; i < v.size(); ++i)
		{
			std::cout << v[i] << std::endl;
			unsigned int firstCol = this->getTopLeft().x + ((cols - v[i].size()) / 2);
			std::cout << "First line to write on : " << firstCol << std::endl;
		}
	}

private:
	CursesWidgetText(void);
	CursesWidgetText(CursesWidgetText const &rhs);
	CursesWidgetText &operator=(CursesWidgetText const &src);

};

#endif
