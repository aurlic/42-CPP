/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:24:24 by aurlic            #+#    #+#             */
/*   Updated: 2024/07/01 15:00:19 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac <= 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		std::cerr << "Usage: ./PMergeMe [numbers to sort]" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int>	vec;
	std::deque<int>		deq;
	for (int i = 1; i < ac; ++i) {
		int	n = std::atoi(av[i]);
		if (n <= 0) {
			std::cerr << "Error: Only positive intergers are allowed." << std::endl;
			return (EXIT_FAILURE);
		}
		vec.push_back(n);
		deq.push_back(n);
	}

	std::cout << "Before:         ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << "   ~~~   " << std::endl;

	clock_t	start, end;

	// USING VECTOR :
	start = clock();
	fordJohnson(vec);
	end = clock();
	double	time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	// USING DEQUE :
	start = clock();
	fordJohnson(deq);
	end = clock();
	double	time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "After (vector): ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After (deque):  ";
	for (size_t i = 0; i < deq.size(); ++i) {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl << "   ~~~   " << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time_vec << " seconds" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << time_deq << " seconds" << std::endl;

	return (EXIT_SUCCESS);
}