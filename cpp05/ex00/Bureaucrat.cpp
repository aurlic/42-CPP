/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:43 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/27 09:40:28 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &b) {
	out << b.getName() << "'s current grade is : " << b.getGrade();
	return (out);
}