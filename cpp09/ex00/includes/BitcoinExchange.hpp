/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:24:01 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/26 10:43:26 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>

std::tm						strToDate(std::string dateStr);

std::map<std::tm, double>	readExchangeRates(const std::string& csvFile);

std::map<std::tm, double>	readInputs(const std::string& infile);

double						findExchangeRate(const std::map<std::tm, double>& exchangeRates, const std::tm& date);
