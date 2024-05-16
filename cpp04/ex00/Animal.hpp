/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:19:19 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:08:13 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		virtual ~Animal();

		Animal(Animal const &other);
		Animal	&operator=(Animal const &rhs);

		virtual void		makeSound() const;
		std::string			getType() const;
};

#endif //ANIMAL_HPP