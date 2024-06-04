/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:58:04 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/04 11:05:15 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdint.h>

struct Data {
	int	i;
};


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);

	public:
		~Serializer();

		Serializer	&operator=(const Serializer &rhs);

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
