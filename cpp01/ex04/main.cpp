/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:18:18 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 17:49:05 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int ac, char **av)
{
	// Check the number of arguments
	if (ac != 4) {
		std::cout << "Usage: ./sed [filename] [str1] [str2]" << std::endl;
		return (1);
	}

	// Check that the input is valid
	if (checkInput(av[1], av[2], av[3]) == false)
		return (1);

	// Replace str1 in file with str2 and copy it to file.replace
	replace(av[1], av[2], av[3]);

	return (0);
}