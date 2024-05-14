/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:15:54 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/14 10:51:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const nb1, float const nb2) : _x(nb1), _y(nb2) {}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point	&Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		Point	tmp(rhs);
		swap(tmp);
	}
	return (*this);
}

void	Point::swap(Point &other) {
	std::swap(const_cast<Fixed&>(_x), const_cast<Fixed&>(other._x));
	std::swap(const_cast<Fixed&>(_y), const_cast<Fixed&>(other._y));
}

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}