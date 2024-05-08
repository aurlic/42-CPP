/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:45:34 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/08 10:56:30 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*brainPtr = &brain;
	std::string	&brainRef = brain;

	std::cout << "String address in memory:   " << &brain << std::endl;
	std::cout << "Address stored in brainPtr: " << brainPtr << std::endl;
	std::cout << "Address stored in brainRef: " << &brainRef << std::endl;

	std::cout << std::endl << "Value of the string:       " << brain << std::endl;
	std::cout << "Value pointed by brainPtr: " << *brainPtr << std::endl;
	std::cout << "Value pointed by brainRef: " << brainRef << std::endl;
	return (0);
}