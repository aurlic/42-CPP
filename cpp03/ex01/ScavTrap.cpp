/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:31:29 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 14:45:57 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap: constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) {
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: destructor called." << std::endl;
}

/* ************************************************************************** */

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/* ************************************************************************** */

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0) {
		std::cout << "ScavTrap: " << this->_name << " doesn't have enough energy to attack..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << this->_name << " is now in Gate Keeper mode." << std::endl;
}

/* ************************************************************************** */