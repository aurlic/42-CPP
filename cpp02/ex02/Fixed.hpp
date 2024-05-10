/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:51:04 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/10 15:06:36 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_bitsNb;

	public:
		//Constructors and destructor:
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		Fixed(int const toFixedValue);
		Fixed(float const toFixedValue);

		//Member functions:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//Assignation operator overload:
		Fixed	&operator=(Fixed const &rhs);

		//Comparison operators overloads:
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		//Arithmetics operators overloads:
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		//Increment and decrement operators overloads:
		Fixed	&operator--(); // --x
		Fixed	&operator++(); // ++x
		Fixed	operator--(int); // x--
		Fixed	operator++(int); // x++

		//Member functions overloads:
		static Fixed		&min(Fixed &nb1, Fixed &nb2);
		static Fixed const	&min(Fixed const &nb1, Fixed const &nb2);
		static Fixed		&max(Fixed &nb1, Fixed &nb2);
		static Fixed const	&max(Fixed const &nb1, Fixed const &nb2);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif //FIXED_HPP