/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:53:32 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/26 09:31:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Convert a date string to a std::tm object.
 *
 * Converts a date string in the format "YYYY-MM-DD" to a std::tm object.
 * The function uses std::istringstream and std::get_time to parse the date
 * string. If the parsing fails, the function throws an invalid_argument
 * exception.
 *
 * @param dateStr the date string to convert.
 * @throw invalid_argument if the date string is not in the correct format.
 * @return a std::tm object representing the parsed date.
 */
std::tm						strToDate(std::string dateStr) {
	std::istringstream	str(dateStr);
	std::tm				tm = {};

	str >> std::get_time(&tm, "%Y-%m-%d");
	if (str.fail()) {
		throw (std::invalid_argument("Invalid date format: " + dateStr));
	}
	
	return (tm);
}

/**
 * @brief Read and return the exchange rate from a csv file.
 *
 * Reads the exchange rate from the csv File passed as parameter.
 * Skip the first line containing "date, exchange_rate", then read each line
 * in a loop until the end of the file.
 * To calculate the rate, parse each line to extract the date and rate, convert
 * the date string to a std::tm object, and store the rate in the map with the
 * date as the key.
 *
 * @param csvFile name of the csv file to read from.
 * @throw runtime_error in case there was an error opening the file.
 * @return a new map containing the exchange rate [date]:[rate].
 */
std::map<std::tm, double> 	readExchangeRates(const std::string& csvFile) {
	std::string					line;
	std::map<std::tm, double>	exchangeRates;
	std::ifstream				file(csvFile);

	if (!file.is_open()) {
		throw (std::runtime_error("Error: couldn't open file " + csvFile));
	}

	std::getline(file, line); // Skip the first line containing : "date,exchange_rate"
	while (std::getline(file, line)) {
		std::string			dateStr, rateStr;
		std::istringstream	iStr(line);
		if (std::getline(iStr, dateStr, ',') && std::getline(iStr, rateStr)) {
			double	rate = std::stod(rateStr);
			std::tm	date = strToDate(dateStr);
			exchangeRates[date] = rate;
		}
	}

	return (exchangeRates);
}

std::map<std::tm, double>	readInputs(const std::string& infile) {
	
}

double						findExchangeRate(const std::map<std::tm, double>& exchangeRates, const std::tm& date);