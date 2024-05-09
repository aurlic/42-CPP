/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:31:51 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/09 11:37:48 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class	Harl {
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif