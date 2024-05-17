/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:41:32 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:06:16 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "[ICE] Constructor called." << std::endl;
}

Ice::~Ice() {
	// std::cout << "[ICE] Denstructor called." << std::endl;
}

Ice::Ice(Ice const &other) : AMateria("ice") {
	// std::cout << "[ICE] Copy constructor called." << std::endl;
	*this = other;
}

Ice	&Ice::operator=(Ice const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria	*Ice::clone() const {
	Ice *tmp = new Ice(*this);
	return (tmp);
}

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}