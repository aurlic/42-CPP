/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:03:09 by arluc             #+#    #+#             */
/*   Updated: 2024/06/28 15:54:40 by arluc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <cctype>
#include <stdexcept>

bool	isOperator(char c);

int		evaluateRPN(const std::string& expression);