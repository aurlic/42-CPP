/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:33:54 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/09 12:17:47 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::_debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::_info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::_warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error() {
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levelArrName[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;;

	while (i < 4 && levelArrName[i].compare(level))
		i++;
	switch (i)
	{
		case (0): {
			this->_debug();
			break;
		}
		case (1): {
			this->_debug();
			this->_info();
			break;
		}
		case (2): {
			this->_debug();
			this->_info();
			this->_warning();
			break;
		}
		case (3): {
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break;
		}
		default: {
			std::cout << "Unrecognized level." << std::endl;
			break;
		}
	}
}