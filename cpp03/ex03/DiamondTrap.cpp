/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:52 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 17:37:27 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap: constructor called." << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: destructor called." << std::endl;
}

/* ************************************************************************** */

void	DiamondTrap::whoAmI() {
	std::cout << "My Diamond name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

/* ************************************************************************** */