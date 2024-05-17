/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:01:45 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 16:05:57 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ICharacter.hpp"

class ICharacter; // forward declaration to avoid circular dependency

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		virtual ~AMateria();

		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria	&operator=(AMateria const &rhs);

		std::string const		&getType() const;
		virtual AMateria		*clone() const = 0;
		virtual void			use(ICharacter &target);
};

#endif //AMATERIA_HPP