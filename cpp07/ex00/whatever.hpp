/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:38:05 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/07 09:56:09 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

template<typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T		min(T a, T b) {
	if (a == b) { 
		return (b);
	} else {
		return (a < b ? a : b);
	}
}

template<typename T>
T		max(T a, T b) {
	if (a == b) { 
		return (b);
	} else {
		return (a > b ? a : b);
	}
}