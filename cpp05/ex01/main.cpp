/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 11:06:33 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
	std::string formName;
	int			grade;
	int			signGrade;
	int			execGrade;

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
	std::cout << "                   ~~~~                   " << std::endl;
	while (true) {
		std::cout << "Please enter a name for your form : ";
		std::cin >> formName;
		if (!isValidName(formName)) {
			std::cout << "Invalid name, must contain alphabetic characters only." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		std::cout << "Please enter the grade required for your form to be signed : ";
		std::cin >> signGrade;
		std::cout << "Please enter the grade required for your form to be executed : ";		
		std::cin >> execGrade;
		break ;
	}
	std::cout << "                   ~~~~                   " << std::endl;
	try {
		Bureaucrat	instance(name, grade);
		Form		form(formName, signGrade, execGrade);
		
		std::cout << form << std::endl;
		instance.signForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}