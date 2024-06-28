/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:22:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/28 13:28:34 by arluc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: incorrect number of arguments." << std::endl;
		return (EXIT_FAILURE);
	}

	std::map<std::string, float> btcPrices = loadBitcoinPrices("src/data.csv"); //different on mac and linux
	if (btcPrices.empty()) {
		std::cerr << "Error: could not load Bitcoin prices." << std::endl;
		return (EXIT_FAILURE);
	}

	processInfile(av[1], btcPrices);

	return (EXIT_SUCCESS);
}