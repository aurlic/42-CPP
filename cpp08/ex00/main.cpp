/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:14:27 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 10:02:00 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int	main() {
	// std::vector<int>	vec = {1, 2, 3, 4, 5}; CPP11 sadly
	// std::list<int>		lst = {10, 20, 30, 40, 50};

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	std::cout << "Searching in vector:" << std::endl;
	try {
		easyfind<std::vector<int> >(vec, 3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		easyfind<std::vector<int> >(vec, 6);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "           ~~~           " << std::endl;

	std::cout << "Searching in list: " << std::endl;
	try {
		easyfind<std::list<int> >(lst, 30);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		easyfind<std::list<int> >(lst, 60);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}