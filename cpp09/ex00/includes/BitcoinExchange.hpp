/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:24:01 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/28 12:08:49 by arluc            ###   ########.fr       */
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

std::map<std::string, float>	loadBitcoinPrices(const std::string &filename);

std::string						getClosestDate(const std::string &date, const std::map<std::string, float> &bitcoinPrices);

void							processInfile(const std::string &filename, const std::map<std::string, float> &bitcoinPrices);

bool							isValidDate(const std::string &date);

bool							isValidValue(const std::string &valueStr, float &value);