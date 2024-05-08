/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:18:29 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 12:17:02 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon(){

}

std::string	&Weapon::getType() {
	std::string	&typeRef = this->_type;

	return (typeRef);
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}