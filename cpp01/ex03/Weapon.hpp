/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:14:38 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 12:17:01 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();

		std::string	&getType();
		void		setType(std::string newType);
};



#endif WEAPON_HPP
