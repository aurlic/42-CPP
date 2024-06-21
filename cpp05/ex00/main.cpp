/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 14:33:28 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <limits>

bool isValidName(const std::string &name) {
	for (std::string::const_iterator it = name.begin(); it != name.end(); ++it) {
		if (!isalpha(*it))
			return false;
	}
	return true;
}

int	main() {
	std::string name;
	int			grade;

	while (true) {
		std::cout << "Please enter a name for your bureaucrat : ";
		std::cin >> name;
		if (std::cin.eof()) {
			return (0);
		}
		if (!isValidName(name)) {
			std::cout << "Invalid name, must contain alphabetic characters only." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		std::cout << std::endl << "Please enter a grade for your bureaucrat : ";
		std::cin >> grade;
		if (std::cin.eof()) {
			return (0);
		}
		break ;
	}
	
	try {
		Bureaucrat	instance(name, grade);
		std::cout << instance << std::endl;
		for (int i = 0; i < 10; i++) {
			instance.decrementGrade();
		}
		std::cout << instance << std::endl;
		for (int i = 0; i < 28; i++) {
			instance.incrementGrade();
		}
		std::cout << instance << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// try {
	// 	Bureaucrat instance("Looser", 178);
	// 	Bureaucrat instance("Cheater", 0);
	// }
	// catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	return (0);
}