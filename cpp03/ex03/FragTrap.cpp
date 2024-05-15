/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:56:18 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 14:59:37 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	std::cout << "FragTrap: constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: destructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) {
	*this = other;
}

/* ************************************************************************** */

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/* ************************************************************************** */

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap: High five !" << std::endl;
}

/* ************************************************************************** */