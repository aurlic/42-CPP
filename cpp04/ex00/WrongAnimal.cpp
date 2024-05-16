/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:25:58 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:30:35 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "[WRONGANIMAL] Constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WRONGANIMAL] Destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	std::cout << "[WRONGANIMAL] Copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "No sound..." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}