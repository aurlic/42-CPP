/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:20:14 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/03 15:08:16 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		~ScalarConverter();

		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &rhs);

		static void		convert(std::string &literal);
};
