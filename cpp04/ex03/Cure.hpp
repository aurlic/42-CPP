/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:33:05 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 13:41:10 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		~Cure();

		Cure(Cure const &other);
		Cure	&operator=(Cure const &rhs);

		virtual	AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif //CURE_HPP