/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:30:20 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:37:21 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
	std::cout << "🤖 Bzzz... Vrrrr... Bzzz... 🤖" << std::endl;
	if (executor.getGrade() <= this->getExecGrade()) {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		std::cout << "The " << this->getName() << " form could not be executed because :" << std::endl;
		throw (AForm::GradeTooLowException());
	}
}

rand() % 2