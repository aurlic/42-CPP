/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:25:58 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 11:20:44 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() {
	std::cout << "[AANIMAL] Constructor called." << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "[AANIMAL] Destructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
	std::cout << "[AANIMAL] Copy constructor called." << std::endl;
	*this = other;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->_type);
}