/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:53:48 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/10 14:09:18 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bitsNb = 8;

//Constructors :
Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits(rhs.getRawBits());      other use with setRawBits()
	*this = src;
}

Fixed::Fixed(int const toFixedValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = toFixedValue * (1 << _bitsNb);
}

Fixed::Fixed(float const toFixedValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(toFixedValue * (1 << _bitsNb));
}


//Member functions :
int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(this->_fixedValue) / (1 << _bitsNb);
}

int 	Fixed::toInt() const {
	return this->_fixedValue / (1 << _bitsNb);
}


//Operator overloads :
Fixed	&Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedValue = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}