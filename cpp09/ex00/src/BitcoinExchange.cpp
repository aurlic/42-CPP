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

// Function to load Bitcoin prices from a CSV file
std::map<std::string, float> loadBitcoinPrices(const std::string &filename) {
    std::map<std::string, float> bitcoinPrices;
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return bitcoinPrices;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
            bitcoinPrices[date] = static_cast<float>(std::atof(priceStr.c_str()));
        }
    }

    file.close();
    return bitcoinPrices;
}

// Function to process the input file and print the results
void processInputFile(const std::string &filename, const std::map<std::string, float> &bitcoinPrices) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the header line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing spaces
            valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v")); // Trim leading spaces

            float value;
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
            } else if (!isValidValue(valueStr, value)) {
                std::cerr << "Error: invalid value => " << valueStr << std::endl;
            } else {
                std::string closestDate = getClosestDate(date, bitcoinPrices);
                float price = bitcoinPrices.find(closestDate)->second;
                std::cout << date << " => " << value << " = " << (value * price) << std::endl;
            }
        } else {
            std::cerr << "Error: bad input format => " << line << std::endl;
        }
    }

    file.close();
}

// Function to find the closest date in the past
std::string getClosestDate(const std::string &date, const std::map<std::string, float> &bitcoinPrices) {
    std::map<std::string, float>::const_iterator it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.end() || it->first != date) {
        if (it != bitcoinPrices.begin()) {
            --it;
        }
    }
    return it->first;
}

// Function to validate the date format (YYYY-MM-DD)
bool isValidDate(const std::string &date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= 31);
}

// Function to validate the value and convert it to float
bool isValidValue(const std::string &valueStr, float &value) {
    char* endptr;
    value = std::strtof(valueStr.c_str(), &endptr);
    if (*endptr != '\0' || value < 0 || value > 1000) {
        return false;
    }
    return true;
}