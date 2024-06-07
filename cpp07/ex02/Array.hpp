/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:44:33 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/07 12:00:44 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

template<typename T>
class Array
{
	private :
		T*			_array;
		std::size_t	_size;

	public :
		Array() : _array(new T[0]), _size(0) {}
		~Array() { delete[] this->_array; }

		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
			for (std::size_t i = 0; i < _size; ++i) {
				_array[i] = other._array[i];
			}
		}

		Array	operator=(const Array &rhs) {
			if (this != &rhs) {
				delete[] _array;
				_array = new T[rhs._size];
				_size = rhs._size;
				for (std::size_t i = 0; i < _size; ++i) {
					_array[i] = rhs._array[i];
				}
			}
			return (*this);
		}
		T	&operator[](std::size_t index) {
			if (index >= _size) {
				throw (InvalidIndexException());
			}
			return (_array[index]);
		}

		std::size_t size() const { return this->_size; }

		class InvalidIndexException : public std::exception {
			public : virtual const char * what() const throw() {
				return ("Invalid index: index is out of array bounds.");
			}
		};
};
