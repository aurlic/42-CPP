/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:40:25 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:59:56 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		~Brain();

		Brain(Brain const &other);
		Brain	&operator=(Brain const &rhs);
};

#endif //BRAIN_HPP