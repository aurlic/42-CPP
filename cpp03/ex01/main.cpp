/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:06:43 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 14:47:49 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	bot1("Bob");

	bot1.attack("a big bad guy");
	// bot1.getHP();
	bot1.takeDamage(50);
	// bot1.getHP();
	bot1.beRepaired(49);
	// bot1.getHP();
	bot1.takeDamage(98);
	// bot1.getHP();
	bot1.guardGate();

	return (0);
}