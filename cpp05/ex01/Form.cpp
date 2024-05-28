/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:22:27 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 10:56:53 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Empty"), _signed(false), _signGrade(0), _execGrade(0) {}

Form::~Form() {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){	
	if (signGrade < 1 || execGrade < 1) {
		throw (Form::GradeTooHighException());
	} else if (signGrade > 150 || execGrade > 150) {
		throw (Form::GradeTooLowException());
	}
}

Form::Form(Form const &other) : _name(other.getName()), _signed(false), _signGrade(other.getSignedGrade()), _execGrade(other.getExecGrade()){
	*this = other;
}

Form	&Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		Form tmp(rhs);
		*this = tmp;
	}
	return (*this);
}

std::string const	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	if (_signed == true)
		return (true);
	return (false);
}

int	Form::getSignedGrade() const {
	return (_signGrade);
}

int	Form::getExecGrade() const {
	return (_execGrade);
}

bool	Form::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
		return (true);
	}
	else {
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, Form const &b) {
	out << "Form : " << b.getName() << std::endl;
	out << "Signed : " << b.getSigned() << std::endl;
	out << "Sign Grade : " << b.getSignedGrade() << std::endl;
	out << "Exec Grade : " << b.getExecGrade() << std::endl;
	return (out);
}