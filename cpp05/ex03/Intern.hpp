/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:44:06 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/29 14:49:40 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();

		Intern(const Intern &other);
		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(std::string fornName, std::string target);
};