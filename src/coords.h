/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coords.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 20:09:54 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 20:20:27 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COORDS_H
#define COORDS_H

struct coords
{
	coords(unsigned int abs, unsigned int ord) : x(abs), y(ord){}
	int x;
	int y;
};

#endif
