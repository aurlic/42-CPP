/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 14:38:23 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
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
	std::string	name;
	int			grade;

	while (true) {
		std::cout << "Please enter a name for your bureaucrat : ";
		std::cin >> name;
		if (!isValidName(name)) {
			std::cout << "Invalid name, must contain alphabetic characters only." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		std::cout << "Please enter a grade for your bureaucrat : ";
		std::cin >> grade;
		break ;
	}
	Bureaucrat	worker(name, grade);
	std::cout << "                   ~~~~                   " << std::endl;

	// AForm	instance(); Can not be intanciated because abstract
	
	// PRESIDENTIAL PARDON FORM
	// PresidentialPardonForm	presForm("Bad guy");
	// try {
	// 	presForm.execute(worker);
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// ROBOTOMY REQUEST FORM
	RobotomyRequestForm	robotForm("Human");
	try {
		robotForm.execute(worker);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// SHRUBBERY CREATION FORM
	// ShrubberyCreationForm	shrubForm("cool");
	// try {
	// 	shrubForm.execute(worker);
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	return (0);
}