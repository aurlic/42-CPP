/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:02:36 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 11:02:51 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

		void	execute(const Bureaucrat &executor);
};
