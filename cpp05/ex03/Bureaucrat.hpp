/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:17:30 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:07:26 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <algorithm>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade(); // ++ and -- overload useless because memeber function required.
		void		decrementGrade(); 
		void		signForm(AForm &form);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too low !");}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return ("Grade is too high !");}
		};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &b);
