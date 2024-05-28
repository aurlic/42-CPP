/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:43 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 11:02:18 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) {
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		this->_grade = other._grade;
		const_cast<std::string&>(_name) = other._name; // Temporarily remove the 'const' qualifier
	}
	return (*this);
}

std::string	Bureaucrat::getName() const {
	return (_name);
}

int			Bureaucrat::getGrade() const {
	return (_grade);
}

void		Bureaucrat::incrementGrade() {
	_grade--;
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void		Bureaucrat::decrementGrade() {
	_grade++;
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::signForm(Form &form) {
	if (form.beSigned(*this) == true) {
		std::cout << this->_name << " has signed " << form.getName() << "'s form." << std::endl;
	} else {
		std::cout << this->_name << " could not sign " << form.getName() << "'s form because his grade is " \
		<< this->_grade << ", and the required grade to sign the form was " << form.getSignedGrade() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &b) {
	out << b.getName() << "'s current grade is : " << b.getGrade();
	return (out);
}