/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:19:27 by aurlic            #+#    #+#             */
/*   Updated: 2024/07/01 14:55:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	sortPair(std::vector<int> &sorted, int n) {
	std::vector<int>::iterator	it = std::lower_bound(sorted.begin(), sorted.end(), n);
	sorted.insert(it, n);
}

void	sortPair(std::deque<int> &sorted, int n) {
	std::deque<int>::iterator	it = std::lower_bound(sorted.begin(), sorted.end(), n);
	sorted.insert(it, n);
}

void	fordJohnson(std::vector<int> &vec) {
	std::vector<std::vector<int> >	pairs;
	int								n = vec.size();

	for (int i = 0; i < n; ++i) {
		if (i + 1 < n) {
			if (vec[i] > vec[i + 1]) {
				std::swap(vec[i], vec[i + 1]);
			}
			std::vector<int>	pair;
			pair.push_back(vec[i]);
			pair.push_back(vec[i + 1]);
			pairs.push_back(pair);
			++i;
		} else {
			std::vector<int> last;
			last.push_back(vec[i]);
			pairs.push_back(last);
		}
	}

	std::vector<int>	sorted;
	for (size_t i = 0; i < pairs.size(); ++i) {
		for (size_t j = 0; j < pairs[i].size(); ++j) {
			sortPair(sorted, pairs[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		vec[i] = sorted[i];
	}
}

void	fordJohnson(std::deque<int> &deq) {
	std::vector<std::deque<int> >	pairs;
	int								n = deq.size();

	for (int i = 0; i < n; ++i) {
		if (i + 1 < n) {
			if (deq[i] > deq[i + 1]) {
				std::swap(deq[i], deq[i + 1]);
			}
			std::deque<int>	pair;
			pair.push_back(deq[i]);
			pair.push_back(deq[i + 1]);
			pairs.push_back(pair);
			++i;
		} else {
			std::deque<int> last;
			last.push_back(deq[i]);
			pairs.push_back(last);
		}
	}

	std::deque<int>	sorted;
	for (size_t i = 0; i < pairs.size(); ++i) {
		for (size_t j = 0; j < pairs[i].size(); ++j) {
			sortPair(sorted, pairs[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		deq[i] = sorted[i];
	}
}