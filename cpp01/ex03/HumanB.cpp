/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:36 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 12:04:49 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {

}

HumanB::~HumanB() {

}

void	HumanB::attack() {
	std::cout << this->_name << "attacks with their " << this->_weapon._getType() << std::endl;
}