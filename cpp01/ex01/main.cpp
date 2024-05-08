/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:47:46 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 10:42:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int			N;
	std::string	name;

	// Number of zombies in horde && handling of ctrl+D
	std::cout << "Choose the number of zombies in the horde: ";
	while (!(std::cin >> N) || N <= 0)
	{
		if (std::cin.eof())
		{
			std::cerr << "\n\033[1;31mError: Unexpected end of input.\033[0m" << std::endl;
			return (1);
		}
		
		std::cout << "Invalid input type, please enter a positive int: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Name of zombies in horde && handling of ctrl+D
	std::cout << "Choose the name of the zombies in the horde: ";
	if (!(std::cin >> name))
	{
		if (std::cin.eof())
		{
			std::cerr << "\n\033[1;31mError: Unexpected end of input.\033[0m" << std::endl;
			return (1);
		}
		std::cerr << "Error: Failed to read name input." << std::endl;
		return (1);
	}

	// Allocation of the horde && Error handling
	Zombie	*horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << "Error: Failed to create zombie horde." << std::endl;
		return (1);
	}

	// Printing of announcement
	for (int i = 0; i < N; i++)
	{
		std::cout << i << " -> ";
		horde[i].announce();
	}

	// Freeing of the horde
	delete [] horde;
	return (0);
}