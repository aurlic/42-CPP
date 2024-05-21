/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:27:24 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/21 08:59:31 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <limits>

int main()
{
	// Dog basic;
	// {
	// 	Dog tmp = basic;
	// }
	Animal	*tab[100];
	int		size = 0;

	while (true) {
		std::cout << "Please enter the array size: ";
		if (std::cin >> size) {
			break;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer.\n";
		}
	}
	for (int i = 0; i < size; ++i) {
		if (i < size / 2) {
			tab[i] = new Dog();
		}
		else if (i >= size / 2) {
			tab[i] = new Cat();
		}
	}

	for (int i = 0; i < size; ++i) {
		delete tab[i];
	}

	return (0);
}