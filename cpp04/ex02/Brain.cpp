/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:43:18 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:58:52 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[BRAIN] Constructor called." << std::endl;
}

Brain::~Brain() {
	std::cout << "[BRAIN] Destructor called." << std::endl;
}

Brain::Brain(Brain const &other) {
	std::cout << "[BRAIN] Copy constructor called." << std::endl;
	*this = other;
}

Brain	&Brain::operator=(Brain const &rhs) {
	if (this != &rhs)
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = rhs.ideas[i];
	return (*this);
}
