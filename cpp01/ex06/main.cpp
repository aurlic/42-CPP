/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:01:05 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/09 12:17:26 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./HarlFilter [LEVEL]" << std::endl;
		return (0);
	}
	Harl	harl;
	harl.complain(av[1]);
	return (0);
}