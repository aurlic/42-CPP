/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:59:50 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 15:58:49 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
}

HumanA::~HumanA() {

}

void	HumanA::attack() const{
	if (!this->_weapon.getType().empty())
		std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << _name << " can't attack without a weapon !" << std::endl;
}