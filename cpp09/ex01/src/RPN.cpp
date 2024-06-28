/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arluc <arluc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:53:55 by arluc             #+#    #+#             */
/*   Updated: 2024/06/28 16:11:22 by arluc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(char c) {
	return (std::string("+-*/").find(c) != std::string::npos);
}

int	evaluateRPN(const std::string& expression) {
	std::stack<int>	stack;

	for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
		char	c = *it;
		
		if (std::isdigit(c)) {
			stack.push(c - '0');
		} else if (c == ' ') {
			continue ;
		} else if (isOperator(c)) {
			if (stack.size() < 2) {
				throw (std::runtime_error("Invalid RPN expression."));
			}
			int	n2 = stack.top();
			stack.pop();
			int	n1 = stack.top();
			stack.pop();

			switch (c) {
				case '+':
					stack.push(n1 + n2);
					break ;
				case '-':
					stack.push(n1 - n2);
					break ;
				case '*':
					stack.push(n1 * n2);
					break ;
				case '/':
					if (n2 == 0) {
						throw (std::runtime_error("Division by zero."));
					}
					stack.push(n1 / n2);
					break;
				default:
					throw (std::runtime_error("Invalid operator encoutered: " + std::string(1, c)));
			}
		}
	}
	if (stack.size() != 1) {
		throw (std::runtime_error("Invalid RPN expression."));
	}

	return (stack.top());
}