/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   CursesWidgetHost.cpp                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 17:12:59 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 17:54:03 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "CursesWidgetHost.hpp"

CursesWidgetHost::CursesWidgetHost(void){}

CursesWidgetHost::~CursesWidgetHost(void){}

void CursesWidgetHost::displayData(void)
{
	std::string data = this->_hostname.getData();
	std::cout << data << std::endl;
}

