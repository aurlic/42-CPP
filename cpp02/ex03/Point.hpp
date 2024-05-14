/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:10:09 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/14 13:32:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <algorithm>

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		// Constructors and destructor:
		Point();
		~Point();
		Point(float const nb1, float const nb2);
		Point(Point const &other);

		// Assignation operator overload:
		Point	&operator=(Point const &rhs);

		void	swap(Point &other);
		
		// Getters:
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POINT_HPP