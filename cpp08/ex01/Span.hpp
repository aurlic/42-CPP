/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:34:59 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/14 16:17:53 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:
		Span(unsigned int N);
		~Span();

		Span(const Span &other);
		Span &operator=(const Span &rhs);

		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

		template<typename Iterator>
		void	addRange(Iterator first, Iterator last) {
			while (first != last) {
				if (_vec.size() >= _N) {
					throw SpanFullException();
				}
				_vec.push_back(*first);
				++first;
			}
		}

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span already containing maximum amount of values.";
				}
		};
		class InsufficientContentException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough number to find span.";
				}
		};
};