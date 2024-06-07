/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:57:31 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/07 10:27:08 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <string>

template<typename T>
void	iter(T* ptr, std::size_t len, void (*f)(T &)) {
	for (std::size_t i = 0; i < len; ++i) {
		f(ptr[i]);
	}
}