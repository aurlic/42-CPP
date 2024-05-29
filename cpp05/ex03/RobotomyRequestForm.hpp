/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:55 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/28 16:39:37 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

		void	execute(const Bureaucrat &executor);
};
