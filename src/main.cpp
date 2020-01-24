/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 19:09:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 22:08:34 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

// #include "Logger.hpp"
// #include "Monitor.hpp"

#include "CursesWidgetText.tpp"
#include "HostnameModule.hpp"

#include "coords.h"


int main(void)
{

	CursesWidgetText<HostnameModule> mod(coords(0,0), coords(100, 100));
	mod.displayData();
	std::cout << mod.getTopLeft().x <<  " " << mod.getTopLeft().y << std::endl;
	std::cout << mod.getBottomRight().x <<  " " << mod.getBottomRight().y << std::endl;
	return (0);
}
