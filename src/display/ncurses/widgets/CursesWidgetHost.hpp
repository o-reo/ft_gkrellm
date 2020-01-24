/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetHost.hpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:10:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 17:53:57 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CURSESWIDGET_HPP
#define CURSESWIDGET_HPP

#include "HostnameModule.hpp"

class CursesWidgetHost
{
public:
	CursesWidgetHost(void);
	~CursesWidgetHost(void);

	void displayData(void);

private:
	CursesWidgetHost(CursesWidgetHost const &rhs);
	CursesWidgetHost &operator=(CursesWidgetHost const &src);

	HostnameModule _hostname;
};

#endif
