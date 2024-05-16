/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:25:58 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:01:33 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "[ANIMAL] Constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "[ANIMAL] Destructor called." << std::endl;
}

Animal::Animal(Animal const &other) {
	std::cout << "[ANIMAL] Copy constructor called." << std::endl;
	*this = other;
}

Animal	&Animal::operator=(Animal const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "No sound..." << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}