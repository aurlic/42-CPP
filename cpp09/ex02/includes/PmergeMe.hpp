/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:27:18 by aurlic            #+#    #+#             */
/*   Updated: 2024/07/01 14:37:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include <stdexcept>
#include <algorithm>

void	sortPair(std::vector<int> &sorted, int n);
void	sortPair(std::deque<int> &sorted, int n);

void	fordJohnson(std::vector<int> &vec);
void	fordJohnson(std::deque<int> &deq);