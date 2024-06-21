/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:17:29 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 10:10:34 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

// int	main() {
// 	const int	N = 5;
// 	Span		sp(N);

// 	try {
// 		sp.addNumber(42);
// 		sp.addNumber(84);
// 		sp.addNumber(0);
// 		sp.addNumber(60);
// 		sp.addNumber(1123);
// 		// sp.addNumber(6); // No room left in span
// 	} catch (const Span::SpanFullException &e) {
// 		std::cerr << "Error adding number: " << e.what() << std::endl;
// 		return (EXIT_FAILURE);
// 	}

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }

// int main() {
// 	const int	N = 10000; // Amount of random numbers generated
// 	Span		sp(N);

// 	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// // ADDNUMBER METHOD :
	// for (int i = 0; i < N; ++i) {
	// 	int	number = std::rand() % 100000;
	// 	sp.addNumber(number);
	// }

	// // ADDRANGE METHOD :
	// std::vector<int> randomNumbers(N);
	// std::generate(randomNumbers.begin(), randomNumbers.end(), std::rand);
	// try {
	// 	sp.addRange(randomNumbers.begin(), randomNumbers.end());
	// } catch (const Span::SpanFullException &e) {
	// 	std::cerr << "Error adding number: " << e.what() <<std::endl;
	// 	return (EXIT_FAILURE);
	// }
// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
// 	return (EXIT_SUCCESS);
// }