/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:14:40 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 15:21:29 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		DiamondTrap();

	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &other);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &rhs);

		void	whoAmI();
};

#endif //DIAMONDTRAP_HPP