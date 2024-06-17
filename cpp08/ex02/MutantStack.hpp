/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:50 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/17 17:09:54 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

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
		const_iterator			begin() const	{ return (this->c.begin()); }
		iterator				end()			{ return (this->c.end()); }
		const_iterator			end() const		{ return (this->c.end()); }
		reverse_iterator		rbegin() 		{ return (this->c.rbegin()); }
		const_reverse_iterator	rbegin() const	{ return (this->c.rbegin()); }
		reverse_iterator		rend()			{ return (this->c.rend()); }
		const_reverse_iterator	rend() const	{ return (this->c.rend()); }
};