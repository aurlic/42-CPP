/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:46:22 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 15:24:57 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <stdio.h>

int	main(void)
{
	PhoneBook	rep;
	std::string	input;

	rep.launch();
	std::cin >> input;
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
			rep.addContact();
		else if (input.compare("SEARCH") == 0)
			rep.search(input);
		std::cin >> input;
	}
	return (0);
}
