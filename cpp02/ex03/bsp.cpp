/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:13:37 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/14 14:48:35 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed nb) {
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static Fixed	area(Point const a, Point const b, Point const c) {
	return (((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) + 
			(c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abcArea = abs(area(a, b, c));
	Fixed	pabArea = abs(area(point, a, b));
	Fixed	pbcArea = abs(area(point, b, c));
	Fixed	pcaArea = abs(area(point, c, a));
	if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
		return (false);
	return (abcArea == pabArea + pbcArea + pcaArea);
}