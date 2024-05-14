/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:11:31 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/14 14:48:09 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	// Example 1: Point inside the triangle
	Point a1(1, 1);
	Point b1(5, 10);
	Point c1(10, 1);
	Point p1(5, 5);  // Point inside the triangle

	if (bsp(a1, b1, c1, p1)) {
		std::cout << "Point (5, 5) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (5, 5) is not inside the triangle" << std::endl;
	}

	// Example 2: Point outside the triangle
	Point a2(1, 1);
	Point b2(5, 10);
	Point c2(10, 1);
	Point p2(12, 5);  // Point outside the triangle

	if (bsp(a2, b2, c2, p2)) {
		std::cout << "Point (12, 5) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (12, 5) is not inside the triangle" << std::endl;
	}

	// Example 3: Point on one of the sides of the triangle
	Point a3(1, 1);
	Point b3(5, 10);
	Point c3(10, 1);
	Point p3(5, 1);  // Point on the side of the triangle

	if (bsp(a3, b3, c3, p3)) {
		std::cout << "Point (5, 1) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (5, 1) is not inside the triangle" << std::endl;
	}

	return 0;
}