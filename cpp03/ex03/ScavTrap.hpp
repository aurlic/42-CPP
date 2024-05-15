/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:27:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 15:27:15 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		ScavTrap();

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();

		ScavTrap	&operator=(ScavTrap const &rhs);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif //SCAVTRAP_PP