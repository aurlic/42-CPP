/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:51:04 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/10 14:08:29 by aurlic           ###   ########.fr       */
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
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		Fixed(int const toFixedValue);
		Fixed(float const toFixedValue);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif //FIXED_HPP