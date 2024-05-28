/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:15:24 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <limits>

bool isValidName(const std::string &name) {
	for (std::string::const_iterator it = name.begin(); it != name.end(); ++it) {
		if (!isalpha(*it))
			return false;
	}
	return true;
}

int	main() {
	// AForm	instance(); Can not be intanciated because abstract
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

	// PRESIDENTIAL PARDON FORM
	// PresidentialPardonForm	presForm("Bad guy");
	// try {
	// 	presForm.execute(worker);
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }


	return (0);
}