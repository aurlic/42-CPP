/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:50 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 10:21:12 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;

		MutantStack() : std::stack<T, Container>() {}
		~MutantStack() {}

		MutantStack(const MutantStack<T, Container> &other) : std::stack<T, Container>(other) {}
		MutantStack<T, Container>	&operator=(const MutantStack<T, Container> &rhs) {
			if (this != &rhs) {
				std::stack<T, Container>::operator=(rhs);
			}
			return (*this);
		}

		// Iterator functions :
		iterator				begin()			{ return (this->c.begin()); }
		iterator				end()			{ return (this->c.end()); }
		reverse_iterator		rbegin() 		{ return (this->c.rbegin()); }
		reverse_iterator		rend()			{ return (this->c.rend()); }
};