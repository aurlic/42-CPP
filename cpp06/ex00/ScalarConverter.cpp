/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:25:00 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/04 09:52:02 by aurlic           ###   ########.fr       */
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
	float		toFloat = 0;
	double		toDouble = 0;
	std::string	toChar = "";
	std::string	extra[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	// Check if literal is a char
	if (literal.length() == 1 && !std::isdigit(literal[0])) { // Check only 1 char and not digit
		int	asciiValue = static_cast<int>(literal[0]);
		if (asciiValue >= std::numeric_limits<char>::min() && asciiValue <= std::numeric_limits<char>::max()) { // Check that number isn't overflow or underflow
			toChar = literal[0];
			std::cout << "char : " << toChar << std::endl;
			std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(toChar[0]) << std::endl;
			std::cout << "double: " << static_cast<double>(toChar[0]) << std::endl;
			return ;
		}
	}

	// Convert if literal is a number
	toInt = std::atoi(literal.c_str()); // c.str() converts std::string to C_style string for atoi, atof, ...

	// Check if literal is float, int or double
	if (literal[literal.length() - 1] == 'f') {
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

	// Check that toInt is within the max and min int
	if (toChar == "") {
		if (toInt >= std::numeric_limits<char>::min() && toInt <= std::numeric_limits<char>::max()) {
			toChar = std::string("'") + static_cast<char>(toInt) + std::string("'");
		} else {
			toChar = "Non printable";
		}
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