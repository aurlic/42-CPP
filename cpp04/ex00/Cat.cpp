/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:37:44 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:01:36 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[CAT] Constructor called." << std::endl;
	_type = "Cat";
}

Cat::~Cat() {
	std::cout << "[CAT] Destructor called." << std::endl;
}

Cat::Cat(Cat const &other) {
	std::cout << "[CAT] Copy constructor called." << std::endl;
	*this = other;
}

Cat	&Cat::operator=(Cat const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow !" << std::endl;
}
