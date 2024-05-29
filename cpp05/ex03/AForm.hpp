/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:22:28 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:18:14 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		AForm();
		virtual ~AForm();

		AForm(std::string _name, int signGrade, int execGrade);
		AForm(AForm const &other);
		AForm	&operator=(AForm const &rhs);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getSignedGrade() const;
		int 				getExecGrade() const;

		bool				beSigned(Bureaucrat bureaucrat);
		virtual void		execute(const Bureaucrat &executor) = 0;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too low !");}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too high !");}
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &b);