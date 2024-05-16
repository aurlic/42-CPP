/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:37:44 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:11:32 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "[WRONGCAT] Constructor called." << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "[WRONGCAT] Destructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) {
	std::cout << "[WRONGCAT] Copy constructor called." << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "woeM !" << std::endl;
}
