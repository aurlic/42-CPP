/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:21:47 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/14 16:15:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &other) { *this = other; }

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (_vec.size() >= _N) {
		throw SpanFullException();
	}
	_vec.push_back(n);
}

int	Span::shortestSpan() const {
	if (_vec.size() <= 1) {
		throw InsufficientContentException();
	}
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int	minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); ++i) {
		int	span = tmp[i] - tmp[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return (minSpan);
}

int	Span::longestSpan() const {
	if (_vec.size() <= 1) {
		throw InsufficientContentException();
	}
	std::vector<int>::const_iterator minIt = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_vec.begin(), _vec.end());
	return (*maxIt - *minIt);
}