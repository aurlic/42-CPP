/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:25:00 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/03 15:24:34 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this != &rhs) {
	}
	return (*this);
}

void	ScalarConverter::convert(std::string &literal) {
	int			toInt = 0;
	int			toFloat = 0;
	int			toDouble = 0;
	std::string	toChar = "";
	std::string	extra[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	// Check for nan or nanf
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: Impossible conversion" << std::endl;
		std::cout << "int: Impossible conversion" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	// Check if literal is a char
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) { // Check only 1 char and printable 
		toChar = literal[0];
		std::cout << "char : " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << std::endl;
		return ;
	}

	// Convert if literal is a number
	toInt = std::atoi(literal.c_str()); // c.str() converts std::string to C_style string for atoi, atof, ...

	// Check if literal is float, int or double
	std::size_t	found = literal.find("f");
	if (found != std::string::npos) {
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat); // Upcast because toDouble is a more general type
	} else {
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble); // Downcast because toFloat reduces the precision and range
	}

	// Find special cases and flag them
	for (int i = 0; i < 6; ++i) {
		if (literal == extra[i]) {
			toChar = "Impossible conversion";
			break ;
		}
	}

	if (toChar == "" && std::isprint(toInt)) { // Check that toInt can be printed
		toChar = std::string("'") + static_cast<char>(toInt) + std::string("'");
	} else if (toChar == "") {
		toChar = "Non printable";
	}

	// Printing
	std::cout << "char: " << toChar << std::endl;
	if (toChar == "Impossible conversion") {
		std::cout << "int: Impossible conversion" << std::endl;
	} else {
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "Impossible conversion" && toFloat == 0) {
		std::cout << "float: Impossible conversion" << std::endl;
		std::cout << "double: Impossible conversion" << std::endl;
	} else {
		if (toChar != "Impossible conversion" && toFloat - static_cast<int>(toFloat) == 0) { // Check if float is a whole number
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} else {
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}