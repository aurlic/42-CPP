/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:58:46 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/04 15:15:22 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int	main(void) {
	for (int i = 0; i < 10; ++i) {
		Base *p = generate();
		identify(p);
		identify(*p);
		delete p;
		std::cout << "-------------------------------------------------" << std::endl;
		usleep(100000);
	}
	return (EXIT_SUCCESS);
}