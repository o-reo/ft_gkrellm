/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 19:09:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 02:14:00 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

// #include "Logger.hpp"
// #include "Monitor.hpp"

#include "CursesDisplay.hpp"



#include "SFMLDisplay.hpp"

int main(void)
{
	SFMLDisplay dis;
	dis.render();
	CursesDisplay cursesDisp;
	cursesDisp.render();
	return (0);
}
