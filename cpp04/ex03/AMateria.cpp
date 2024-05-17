/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:08:58 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:06:35 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "[AMATERIA] Constructor called." << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "[AMATERIA] Destructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &other) {
	// std::cout << "[AMATERIA] Copy constructor called." << std::endl;
	*this = other;
}

AMateria			&AMateria::operator=(AMateria const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const	&AMateria::getType() const {
	return this->_type;
}

void				AMateria::use(ICharacter &target) {
	std::cout << this->_type << " used on " << target.getName() << std::endl;
}