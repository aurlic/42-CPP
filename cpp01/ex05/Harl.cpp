/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:33:54 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/09 12:01:01 by aurlic           ###   ########.fr       */
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
	// void	(Harl::*debugPtr)() = &Harl::_debug;
	// void	(Harl::*infoPtr)() = &Harl::_info;
	// void	(Harl::*warningPtr)() = &Harl::_warning;
	// void	(Harl::*errorPtr)() = &Harl::_error;
	void	(Harl::*functionArrPtr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning,  &Harl::_error};
	std::string	levelName[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (!levelName[i].compare(level)) {
			(this->*functionArrPtr[i])();
			return ;
		}
	}
	std::cout << "No matching level detected." << std::endl;
}