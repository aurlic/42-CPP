/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:21:14 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:06:23 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	// std::cout << "[CHARACTER] Constructor called." << std::endl;
}

Character::Character(std::string name) : _name(name) {
	// std::cout << "[CHARACTER] Constructor called." << std::endl;
	for (int i = 0; i < 4; ++i) {
		this->_inv[i] = NULL;
	}
}

Character::~Character() {
	// std::cout << "[CHARACTER] Destructor called." << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_inv[i])
			delete this->_inv[i];
	}
}

Character::Character(Character const &other) {
	std::cout << "[CHARACTER] Copy constructor called." << std::endl;
	*this = other;
}

Character	&Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; ++i) {
			this->_inv[i] = rhs._inv[i];
		}
	}
	return (*this);
}

std::string const	&Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inv[i]) {
			std::cout << this->_name << " equipped " << m->getType() << std::endl;
			this->_inv[i] = m;
			return ;
		}
	}
	std::cout << this->_name << " could not equip " << m->getType() << std::endl;
}

void	Character::unequip(int idx) {
	if (this->_inv[idx]) {
		std::cout << this->_name << " has unequipped " << this->_inv[idx]->getType() << std::endl;
		delete this->_inv[idx];
		this->_inv[idx] = NULL;
	} else {
		std::cout << this->_name << "could not unequip " << this->_inv[idx]->getType() << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (this->_inv[idx])
	{
		std::cout << this->_name << " used " << this->_inv[idx]->getType() << std::endl;
		this->_inv[idx]->use(target);
	} else {
		std::cout << this->_name << " could not use " << this->_inv[idx]->getType() << std::endl;
	}
}
