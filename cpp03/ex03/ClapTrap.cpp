/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:51 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 17:32:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap: constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
	std::cout << "ClapTrap: copy constructor called." << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap: destructor called." << std::endl;
}

/* ************************************************************************** */

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/* ************************************************************************** */

void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap: " << this->_name << " doesn't have enough energy to attack..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap: " << this->_name << " can't take any more damage !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " has taken " << amount << " points of damage ! Ouch !" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap: " << this->_name << " doesn't have enough energy to be repaired..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " repaired itself and regained " << amount << " hit points !" << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
}

/* ************************************************************************** */

void	ClapTrap::getHP() {
	std::cout << this->_name << " has " << this->_hitPoints << " HP." << std::endl;
}