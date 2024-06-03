/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:27:22 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/03 15:12:22 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main() {
	std::string	literal;

	std::cout << "Please input something to be converted: ";
	getline(std::cin, literal);
	if (literal.empty()) {
		std::cout << "Input can't be empty." << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(literal);

	return (EXIT_SUCCESS);
}