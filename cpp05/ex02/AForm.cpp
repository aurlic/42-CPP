/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:22:27 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 14:14:44 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Empty"), _signed(false), _signGrade(0), _execGrade(0) {}

AForm::~AForm() {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){	
	if (signGrade < 1 || execGrade < 1) {
		throw (AForm::GradeTooHighException());
	} else if (signGrade > 150 || execGrade > 150) {
		throw (AForm::GradeTooLowException());
	}
}

AForm::AForm(AForm const &other) : _name(other.getName()), _signed(false), _signGrade(other.getSignedGrade()), _execGrade(other.getExecGrade()){
	*this = other;
}

AForm	&AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::string const	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	if (_signed == true)
		return (true);
	return (false);
}

int	AForm::getSignedGrade() const {
	return (_signGrade);
}

int	AForm::getExecGrade() const {
	return (_execGrade);
}

bool	AForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
		return (true);
	}
	else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, AForm const &b) {
	out << "AForm : " << b.getName() << std::endl;
	out << "Signed : " << b.getSigned() << std::endl;
	out << "Sign Grade : " << b.getSignedGrade() << std::endl;
	out << "Exec Grade : " << b.getExecGrade() << std::endl;
	return (out);
}