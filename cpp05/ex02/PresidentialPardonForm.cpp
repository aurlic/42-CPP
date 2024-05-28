/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:10:10 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:35:24 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("Presidential", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) {
	*this = other;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		_target = rhs._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() <= this->getExecGrade()) {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		std::cout << "The " << this->getName() << " form could not be executed because :" << std::endl;
		throw (AForm::GradeTooLowException());
	}
}