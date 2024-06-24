/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:22:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/24 13:48:22 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc [input_file]" << std::endl;
		exit (EXIT_FAILURE);
	}

	const std::string	csvFile = "data.csv";
	const std::string	infile = av[1];

	try {
		std::map<std::tm, double>	exchangeRates = readExchangeRates(csvFile);
		std::map<std::tm, double>	inputs = readInputs(infile);

		for (std::map<std::tm, double>::const_iterator it = inputs.begin(); it != inputs.end(); ++it) {
			try {
				double	rate = findExchangeRate(exchangeRates, it->first);
				double	result = rate * it->second;
				std::cout << std::put_time(&(it->first), "%y-%m-%d") << " => " << it->second << result << std::endl;
			} catch (const std::runtime_error& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}