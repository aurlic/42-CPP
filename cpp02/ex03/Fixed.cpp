/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:53:48 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/10 15:06:25 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bitsNb = 8;

//Constructors :
Fixed::Fixed() : _fixedValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	// std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits(rhs.getRawBits());      other use with setRawBits()
	*this = src;
}

Fixed::Fixed(int const toFixedValue) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = toFixedValue * (1 << _bitsNb);
}

Fixed::Fixed(float const toFixedValue) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(toFixedValue * (1 << _bitsNb));
}


//Member functions :
int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(this->_fixedValue) / (1 << _bitsNb);
}

int 	Fixed::toInt() const {
	return this->_fixedValue / (1 << _bitsNb);
}


//Assignation operator overload:
Fixed	&Fixed::operator=(Fixed const &rhs) {
	// std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedValue = rhs.getRawBits();
	return (*this);
}

//Comparison operators overloads:
bool	Fixed::operator>(Fixed const &rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

//Arithmetics operators overloads:
Fixed	Fixed::operator+(Fixed const &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//Increment and decrement operators overloads:
Fixed	&Fixed::operator--() {
	--_fixedValue;
	return (*this);
}

Fixed	&Fixed::operator++() {
	++_fixedValue;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}


//Member functions overloads:
Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2) {
	if ( nb1.getRawBits() < nb2.getRawBits() )
		return nb1;
	return nb2;
}

Fixed const 	&Fixed::min(Fixed const &nb1, Fixed const &nb2) {
	if ( nb1.getRawBits() < nb2.getRawBits() )
		return nb1;
	return nb2;
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2) {
	if ( nb1.getRawBits() > nb2.getRawBits() )
		return nb1;
	return nb2;
}

Fixed const	&Fixed::max(Fixed const &nb1, Fixed const &nb2) {
	if ( nb1.getRawBits() > nb2.getRawBits() )
		return nb1;
	return nb2;
}


std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}