/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:02:58 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 14:36:18 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
	*this = other;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		_target = rhs._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	if (this->beSigned(executor) == true) {
		std::cout << executor.getName() << " just signed the form." << std::endl;
	} else {
		throw (AForm::GradeTooLowException());
	}
	if (executor.getGrade() <= this->getExecGrade()) {
		std::string		newFileName = this->_target + "_shrubbery";
		std::ofstream	newFile(newFileName.c_str());
		newFile << "                      ___\n"
				   "                _,-'\"\"   \"\"\"\"`--.\n"
				   "             ,-'          __,,-- \\\n"
				   "           ,'    __,--\"\"\"\"dF      )\n"
				   "          /   .-\"Hb_,--\"\"dF      /\n"
				   "        ,'       _Hb ___dF\"-._,-'\n"
				   "      ,'      _,-\"\"\"\"   \"\"--..__\n"
				   "     (     ,-'                  `.\n"
				   "      `._,'     _   _             ;\n"
				   "       ,'     ,' `-'Hb-.___..._,-'\n"
				   "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
				   "        `--'   \"Hb  HH  dF\"\n"
				   "                \"Hb HH dF\n"
				   "                 \"HbHHdF\n"
				   "                  |HHHF\n"
				   "                  |HHH|\n"
				   "                  |HHH|\n"
				   "                  |HHH|\n"
				   "                  |HHH|\n"
				   "                  dHHHb\n"
				   "                .dFd|bHb.               o\n"
				   "      o       .dHFdH|HbTHb.          o /\n"
				   "\\  Y  |  \\__,dHHFdHH|HHhoHHb.___ |    Y\n"
				   "##########################################\n";
		newFile.close();
		std::cout << newFileName << " created ! 🌳" << std::endl;
	} else {
		std::cout << "The " << this->getName() << " form could not be executed because :" << std::endl;
		throw (AForm::GradeTooLowException());
	}
}
