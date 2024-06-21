/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:58:23 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 10:00:49 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

class ValueNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Value not found in the container.";
		}
};

template<typename T>
void	easyfind(const T& container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end()) {
		std::cout << "Found " << value << " in the container." << std::endl;
	} else {
		throw ValueNotFoundException();
	}
}