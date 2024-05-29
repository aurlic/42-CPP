/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:30:20 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 14:36:41 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		_target = rhs._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) {
	if (this->beSigned(executor) == true) {
		std::cout << executor.getName() << " just signed the form." << std::endl;
	} else {
		throw (AForm::GradeTooLowException());
	}
	std::cout << "🤖 Bzzz... Vrrrr... Bzzz... 🤖" << std::endl;
	if (executor.getGrade() <= this->getExecGrade()) {
		std::srand(std::time(NULL));
		if (std::rand() % 2 == 1) {
			std::cout << _target << " has been robotomized ! 🧑➜🤖✅" << std::endl;
		} else {
			std::cout << _target << " couldn't be robotomized... 🧑➜🤖❌" << std::endl;
		}
	} else {
		std::cout << "The " << this->getName() << " form could not be executed because :" << std::endl;
		throw (AForm::GradeTooLowException());
	}
}
