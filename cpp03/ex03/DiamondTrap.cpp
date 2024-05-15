/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:52 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 15:28:53 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

}

DiamondTrap::DiamondTrap(DiamondTrap const &other) {
	*this = other;
}

/* ************************************************************************** */


DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/* ************************************************************************** */

void	DiamondTrap::whoAmI() {
	std::cout << "My Diamond name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

/* ************************************************************************** */