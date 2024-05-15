/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:51:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 14:56:15 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap(std::string const name);
		FragTrap(FragTrap const &other);
		~FragTrap();

		FragTrap	&operator=(FragTrap const &rhs);

		void	highFivesGuys();
};

#endif //FRAGTRAP_HPP