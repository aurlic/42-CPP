/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:18:11 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/04 11:01:50 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data*	data = new Data;

	std::cout << "data address: " << data << std::endl;
	std::cout << "serialized data: " << Serializer::serialize(data) << std::endl;
	std::cout << "deserialized data: " << Serializer::deserialize(Serializer::serialize(data)) << std::endl;

	delete data;

	return (EXIT_SUCCESS);
}