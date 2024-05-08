/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:00:16 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 10:42:56 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	
}

Zombie::~Zombie(void){
	std::cout << "\033[0;31m" << this->name << " has been destroyed.\033[0m" << std::endl;
}

void	Zombie::announce(void){
	std::cout << "\033[1;32m" << name << ": BraiiiiiiinnnzzzZ...\033[0m 🧟🧠" << std::endl;
}

void	Zombie::setName(std::string name){
	this->name = name;
}