/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:06:43 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 17:33:32 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap	bot1("Bob");

	bot1.whoAmI();
	bot1.attack("Random chump");
	bot1.getHP();
	bot1.takeDamage(38);
	bot1.getHP();
	bot1.beRepaired(197);
	bot1.getHP();
	return (0);
}