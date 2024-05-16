/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:43:40 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:01:37 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[DOG] Constructor called." << std::endl;
	_type = "Dog";
}

Dog::~Dog() {
	std::cout << "[DOG] Destructor called." << std::endl;
}

Dog::Dog(Dog const &other) {
	std::cout << "[DOG] Copy constructor called." << std::endl;
	*this = other;
}

Dog	&Dog::operator=(Dog const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Bark !" << std::endl;
}