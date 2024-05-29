/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 16:36:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <limits>

bool isValidName(const std::string &name) {
	for (std::string::const_iterator it = name.begin(); it != name.end(); ++it) {
		if (!isalpha(*it))
			return false;
	}
	return true;
}

int	main() {
	Intern someRandomIntern;
	AForm* rrf;

	// rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	// rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	// rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	rrf = someRandomIntern.makeForm("fakeForm", "Bender");

	if (rrf) {
		Bureaucrat	bob("Bob", 1);
		try {
			rrf->execute(bob);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	} else {
		std::cout << "Form creation failed." << std::endl;
	}
	delete rrf;
	return (0);
}