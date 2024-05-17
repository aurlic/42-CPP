/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:43:40 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 10:42:36 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[DOG] Constructor called." << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "[DOG] Destructor called." << std::endl;
	delete _brain;
}

Dog::Dog(Dog const &other) {
	std::cout << "[DOG] Copy constructor called." << std::endl;
	*this = other;
}

Dog	&Dog::operator=(Dog const &rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Bark !" << std::endl;
}