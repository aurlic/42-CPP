/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:53:32 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/26 10:48:26 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Convert a date string to a std::tm object.
 *
 * Converts a date string in the format "YYYY-MM-DD" to a std::tm object.
 * The function manually parses the date string to extract the year, month, and day.
 * If the parsing fails, the function throws an invalid_argument exception.
 *
 * @param dateStr the date string to convert.
 * @throw invalid_argument if the date string is not in the correct format.
 * @return a std::tm object representing the parsed date.
 */
std::tm	strToDate(std::string dateStr) {
	std::tm				tm = {};

	if (sscanf(dateStr.c_str(), "%4d-%2d-%2d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday)) {
		throw (std::invalid_argument("Invalid date format: " + dateStr));
	}

	tm.tm_year -= 1900;	// Adjust years since 1900
	tm.tm_mon -= 1;		// Adjust months since January
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
std::map<std::tm, double>	readExchangeRates(const std::string& csvFile) {
	std::string					line;
	std::map<std::tm, double>	exchangeRates;
	std::ifstream				file(csvFile);

	if (!file.is_open()) {
		throw (std::runtime_error("Error: couldn't open file " + csvFile));
	}

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string			dateStr, rateStr;
		std::istringstream	iStr(line);
		if (std::getline(iStr, dateStr, ',') && std::getline(iStr, rateStr)) {
			std::stringstream ss(rateStr);
			double rate;
			ss >> rate;
			if (ss.fail() || !ss.eof()) {
				std::cerr << "Error: invalid rate => " << rateStr << std::endl;
				continue;
			}

			std::tm	date = strToDate(dateStr);
			exchangeRates[date] = rate;
		}
	}

	return (exchangeRates);
}

std::map<std::tm, double>	readInputs(const std::string& infile) {
	std::string					line;
	std::map<std::tm, double>	inputs;
	std::ifstream				file(infile);

	if (!file.is_open()) {
		throw (std::runtime_error("Error: couldn't open file " + infile));
	}

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string			dateStr, valueStr;
		std::istringstream	iStr(line);
		if (std::getline(iStr, dateStr, '|') && std::getline(iStr, valueStr)) {
			try {
				std::stringstream ss(valueStr);
				double value;
				ss >> value;
				if (ss.fail() || !ss.eof()) {
					std::cerr << "Error: invalid value => " << valueStr << std::endl;
					continue;
				}

				std::tm	date = strToDate(dateStr);

				if (value < 0 || value > 1000) {
					std::cerr << "Error: invalid value => " << valueStr << std::endl;
					continue ;
				}
				inputs[date] = value;
			} catch (const std::invalid_argument& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}

	return (inputs);
}

/**
 * @brief Find the exchange rate for a given date.
 *
 * Finds the exchange rate for a given date from the provided map of exchange rates.
 * If the exact date is not found, the function finds the nearest preceding date.
 * If no preceding date exists, the function throws a runtime_error exception.
 *
 * @param exchangeRates map containing date (std::tm) to exchange rate (double) mappings.
 * @param date the date (std::tm) for which to find the exchange rate.
 * @throw runtime_error if no valid preceding date is found in the map.
 * @return the exchange rate (double) for the given date or the nearest preceding date.
 */
double	findExchangeRate(const std::map<std::tm, double>& exchangeRates, const std::tm& date) {
	std::map<std::tm, double>::const_iterator	it = exchangeRates.lower_bound(date);	// returns an it pointing to first element that is not >= the given key

	if (it == exchangeRates.end() || it->first > date) {
		if (it == exchangeRates.begin()) {
			char	buf[11];
			sprintf(buf, "%04d-%02d-%02d", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday);
			throw (std::runtime_error(std::string("No exchange rate available for date ") + buf));
		}
		--it;
	}

	return (it->second);
}