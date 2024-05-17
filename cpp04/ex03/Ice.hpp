/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:43:29 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 13:43:53 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		~Ice();

		Ice(Ice const &other);
		Ice	&operator=(Ice const &rhs);

		virtual	AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif //ICE_HPP