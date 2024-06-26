/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:22:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/26 10:44:50 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// int	main(int ac, char **av) {
// 	if (ac != 2) {
// 		std::cerr << "Usage: ./btc [input_file]" << std::endl;
// 		exit (EXIT_FAILURE);
// 	}

// 	const std::string	csvFile = "data.csv";
// 	const std::string	infile = av[1];

// 	try {
// 		std::map<std::tm, double>	exchangeRates = readExchangeRates(csvFile);
// 		std::map<std::tm, double>	inputs = readInputs(infile);

// 		for (std::map<std::tm, double>::const_iterator it = inputs.begin(); it != inputs.end(); ++it) {
// 			try {
// 				double	rate = findExchangeRate(exchangeRates, it->first);
// 				double	result = rate * it->second;
// 				std::cout << std::put_time(&(it->first), "%y-%m-%d") << " => " << it->second << result << std::endl;
// 			} catch (const std::runtime_error& e) {
// 				std::cerr << "Error: " << e.what() << std::endl;
// 			}
// 		}
// 	} catch (const std::runtime_error& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 		return (EXIT_FAILURE);
// 	}

// 	return (EXIT_SUCCESS);
// }

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    const std::string exchangeRatesFile = "exchange_rates.csv";
    const std::string inputFile = argv[1];

    try {
        std::map<std::tm, double> exchangeRates = readExchangeRates(exchangeRatesFile);
        std::ifstream input(inputFile.c_str());

        if (!input.is_open()) {
            throw std::runtime_error("Error: couldn't open input file " + inputFile);
        }

        std::string line;
        while (std::getline(input, line)) {
            std::size_t sepPos = line.find('|');
            if (sepPos != std::string::npos) {
                std::string dateStr = line.substr(0, sepPos);
                std::string valueStr = line.substr(sepPos + 1);

                // Trim leading and trailing spaces
                dateStr.erase(dateStr.find_last_not_of(" \n\r\t") + 1);
                dateStr.erase(0, dateStr.find_first_not_of(" \n\r\t"));
                valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
                valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

                try {
                    std::tm date = strToDate(dateStr);
                    std::stringstream ss(valueStr);
                    double value;
                    ss >> value;

                    if (ss.fail() || !ss.eof()) {
                        throw std::invalid_argument("Invalid number format: " + valueStr);
                    }

                    if (value < 0) {
                        std::cout << "Error: not a positive number." << std::endl;
                        continue;
                    } else if (value > 1000) {
                        std::cout << "Error: too large a number." << std::endl;
                        continue;
                    }

                    double rate = findExchangeRate(exchangeRates, date);
                    std::cout << dateStr << " => " << value << " = " << (value * rate) << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cout << "Error: bad input => " << dateStr << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            }
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}