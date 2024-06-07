/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:59:34 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/07 10:28:38 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void print(T& a) {
	std::cout << a << std::endl;
}

template<typename T>
void increment(T& a) {
	++a;
}

int main() {
	// Int array
	int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Original integer array:\n";
	for (int i = 0; i < 10; ++i) {
		std::cout << intArray[i] << " ";
	}
	std::cout << "\n\nPrinting integer array elements:\n";
	::iter(intArray, 10, &print<int>);

	// Increment integer array
	std::cout << "\n\nIncrementing integer array elements:\n";
	::iter(intArray, 10, &increment<int>);
	::iter(intArray, 10, &print<int>);

	// String array
	std::string strArray[4] = {"abc", "dfg", "hij", "klm"};
	std::cout << "\n\nOriginal string array:\n";
	for (int i = 0; i < 4; ++i) {
		std::cout << strArray[i] << " ";
	}
	std::cout << "\n\nPrinting string array elements:\n";
	::iter(strArray, 4, &print<std::string>);

	return (EXIT_SUCCESS);
}