/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:22:28 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/27 13:46:51 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form();
		~Form();

		Form(std::string _name, int signGrade, int execGrade);
		Form(Form const &other);
		Form	&operator=(Form const &rhs);

		std::string const	getName() const;
		bool				getSigned() const;
		int const			getSignedGrade() const;
		int const			getExecGrade() const;

		bool				beSigned(Bureaucrat bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too low !");}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too high !");}
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &b);

#endif // FORM_HPP