/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:46:15 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 15:11:19 by aurlic           ###   ########.fr       */
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
	return (*this);
}

AForm	*Intern::makeForm(std::string fornName, std::string target) {
	std::string	formArr[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm		*forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++) {
		if (fornName == formArr[i]) {
			std::cout << "Intern has created a new " << forms[i]->getName() << " form." << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "No form found matching this: " << fornName << std::endl;
	return (nullptr);
}
