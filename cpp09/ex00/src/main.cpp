/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:22:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/26 17:38:14 by arluc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: incorrect number of arguments." << std::endl;
		return 1;
	}

	std::map<std::string, float> bitcoinPrices = loadBitcoinPrices("data.csv");
	if (bitcoinPrices.empty()) {
		std::cerr << "Error: could not load Bitcoin prices." << std::endl;
		return 1;
	}

	processInputFile(argv[1], bitcoinPrices);

	return (EXIT_SUCCESS);
}