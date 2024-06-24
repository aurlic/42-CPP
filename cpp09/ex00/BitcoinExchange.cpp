/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:53:32 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/24 14:54:29 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::tm						strToDate(std::string dateStr) {
	std::istringstream	str(dateStr);
	std::tm				tm = {};

	str >> std::get_time(&tm, "%Y-%m-%d");
	if (str.fail()) {
		throw (std::invalid_argument("Invalid date format: " + dateStr));
	}
	
	return (tm);
}

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

std::map<std::tm, double>	readInputs(const std::string& infile);

double						findExchangeRate(const std::map<std::tm, double>& exchangeRates, const std::tm& date);