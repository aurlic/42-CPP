// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/24 13:53:32 by aurlic            #+#    #+#             */
// /*   Updated: 2024/06/26 16:30:32 by arluc            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Load Bitcoin prices from a CSV file.
 *
 * This function reads a CSV file containing dates and corresponding Bitcoin prices
 * and stores the data in a map. Each line in the CSV file should contain a date
 * and a price separated by a comma.
 *
 * @param filename The name of the CSV file to load.
 * @return A map where the keys are dates (YYYY-MM-DD) and the values are Bitcoin prices.
 */
std::map<std::string, float> loadBitcoinPrices(const std::string &filename) {
	std::ifstream					file(filename.c_str());
	std::map<std::string, float>	btcPrices;
	std::string						line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (btcPrices);
	}

	while (std::getline(file, line)) {
		std::istringstream	str(line);
		std::string			date;
		std::string			priceStr;

		if (std::getline(str, date, ',') && std::getline(str, priceStr)) {
			btcPrices[date] = static_cast<float>(std::atof(priceStr.c_str()));
		}
	}

	file.close();
	return (btcPrices);
}

/**
 * @brief Process the input file and print results.
 *
 * This function reads the input file containing dates and values to be evaluated.
 * For each entry, it finds the corresponding Bitcoin price from the loaded data,
 * computes the result, and prints it. It also handles errors and prints appropriate
 * error messages.
 *
 * @param filename The name of the input file to process.
 * @param bitcoinPrices A map containing Bitcoin prices indexed by date.
 */
void processInfile(const std::string &filename, const std::map<std::string, float> &bitcoinPrices) {
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream	str(line);
		std::string			date;
		std::string			valueStr;

		if (std::getline(str, date, '|') && std::getline(str, valueStr)) {
			float	value;

			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);			// Trim trailing spaces
			valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));	// Trim leading spaces
			if (!isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
			} else if (!isValidValue(valueStr, value)) {
				std::cerr << "Error: invalid value => " << valueStr << std::endl;
			} else {
				std::string	closestDate = getClosestDate(date, bitcoinPrices);
				float		price = bitcoinPrices.find(closestDate)->second;
				std::cout << date << " => " << value << " = " << (value * price) << std::endl;
			}
		} else {
			std::cerr << "Error: bad input format => " << line << std::endl;
		}
	}

	file.close();
}

/**
 * @brief Find the closest date in the past from the given date.
 *
 * This function finds the closest date in the past (or the exact date if it exists)
 * in the map of Bitcoin prices. It returns the closest previous date if the given
 * date does not exist in the map.
 *
 * @param date The date to find the closest previous date for.
 * @param btcPrices A map containing Bitcoin prices indexed by date.
 * @return The closest previous date as a string in the format YYYY-MM-DD.
 */
std::string getClosestDate(const std::string &date, const std::map<std::string, float> &btcPrices) {
	std::map<std::string, float>::const_iterator	it = btcPrices.lower_bound(date);

	if (it == btcPrices.end() || it->first != date) {
		if (it != btcPrices.begin()) {
			--it;
		}
	}
	return (it->first);
}

/**
 * @brief Validate the date format.
 *
 * This function checks if the given date is in the valid format YYYY-MM-DD.
 * It ensures that the date contains valid year, month, and day values.
 *
 * @param date The date string to validate.
 * @return True if the date is valid, otherwise false.
 */
bool isValidDate(const std::string &date) {
	if (date.length() != 10) {
		return (false);
	}
	if (date[4] != '-' || date[7] != '-') {
		return (false);
	}
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= 31);
}

/**
 * @brief Validate the value and convert it to float.
 *
 * This function checks if the given value string represents a valid number
 * within the range of 0 to 1000. It converts the valid string to a float.
 *
 * @param valueStr The value string to validate and convert.
 * @param value The float variable to store the converted value.
 * @return True if the value is valid, otherwise false.
 */
bool isValidValue(const std::string &valueStr, float &value) {
	char*	endptr;

	value = std::strtof(valueStr.c_str(), &endptr);	// ptr here to show first char not converted
	if (*endptr != '\0' || value < 0 || value > 1000) {
		return (false);
	}
	return (true);
}