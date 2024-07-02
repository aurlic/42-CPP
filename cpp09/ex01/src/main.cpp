/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:48:31 by arluc             #+#    #+#             */
/*   Updated: 2024/07/02 10:13:29 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Not the good number of arguments." << std::endl << "Usage: ./RPN \"expression\"" << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		int	result = evaluateRPN(av[1]);
		std::cout << "Result: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}