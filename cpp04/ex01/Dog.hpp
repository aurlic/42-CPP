/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:37:15 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/17 09:43:36 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		~Dog();

		Dog(Dog const &other);
		Dog	&operator=(Dog const &rhs);

		void	makeSound() const;
};

#endif //DOG_HPP