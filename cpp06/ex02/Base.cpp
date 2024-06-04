/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:11:52 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/04 15:14:13 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base	*generate(void) {
	srand(time(NULL)); // Seed random number with current time
	int	seed = rand() % 3;
	switch (seed) {
		case (0):
			std::cout << "New A class generated." << std::endl;
			return (new A());
		case (1):
			std::cout << "New B class generated." << std::endl;
			return (new B());
		case (2):
			std::cout << "New C class generated." << std::endl;
			return (new C());
		default :
			return (NULL);
	}
}

void	identify(Base* p) {
	std::cout << " ~~ " << std::endl;
	std::cout << "Identify with pointer : ";
	if (dynamic_cast<A*>(p)) {
		std::cout << "Class A identified" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Class B identified" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Class C identified" << std::endl;
	} else {
		std::cout << "Unknown" << std::endl;
	}
}

void	identify(Base& p) {
	std::cout << " ~~ " << std::endl;
	std::cout << "Identify with reference : ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A identified" << std::endl;
		return ;
	} catch (...) {} // Empty catch block (bad practice), ignore error go on.
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B identified" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C identified" << std::endl;
		return ;
	} catch (...) {}
	std::cout << " ~~ " << std::endl;
}