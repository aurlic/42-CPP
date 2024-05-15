/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:06:43 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/15 13:23:58 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	bot1("Bob");

	bot1.attack("Dummy");
	// bot1.getHP();
	bot1.takeDamage(4);
	// bot1.getHP();
	bot1.takeDamage(3);
	// bot1.getHP();
	bot1.beRepaired(10);
	// bot1.getHP();
	bot1.takeDamage(9);
	// bot1.getHP();
}