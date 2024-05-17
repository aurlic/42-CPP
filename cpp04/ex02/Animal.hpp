/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:19:19 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 11:20:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		virtual ~AAnimal();

		AAnimal(AAnimal const &other);
		AAnimal	&operator=(AAnimal const &rhs);

		virtual void		makeSound() const = 0;
		std::string			getType() const;
};

#endif //ANIMAL_HPP