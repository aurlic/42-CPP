/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:46:15 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 16:32:25 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern	&Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string fornName, std::string target) {
	std::string	formArr[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm		*forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm		*result = NULL;

	for (int i = 0; i < 3; i++) {
		if (fornName == formArr[i]) {
			result = forms[i];
			std::cout << "Intern has created a new " << forms[i]->getName() << " form." << std::endl;
		} else {
			delete forms[i];
		}
	}
	if (!result) {
		std::cout << "No form found matching this: " << fornName << std::endl;
	}

	return (result);
}
