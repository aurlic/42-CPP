/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:16:02 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/07 17:26:24 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name;

	std::cout << "1. New zombie name ? :" << std::endl;
	std::cin >> name;
	Zombie	*newZ = newZombie(name);
	newZ->announce();
	delete (newZ);

	std::cout << std::endl << "2. New zombie name ? :" << std::endl;
	std::cin >> name;
	randomChump(name);

	return (0);
}