/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:36:01 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:06:51 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "[CURE] Constructor called." << std::endl;
}

Cure::~Cure() {
	// std::cout << "[CURE] Denstructor called." << std::endl;
}

Cure::Cure(Cure const &other) : AMateria("cure") {
	// std::cout << "[CURE] Copy constructor called." << std::endl;
	*this = other;
}

Cure	&Cure::operator=(Cure const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria	*Cure::clone() const {
	Cure *tmp = new Cure(*this);
	return (tmp);
}

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}