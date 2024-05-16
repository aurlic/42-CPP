/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:37:15 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:07:00 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		~Cat();

		Cat(Cat const &other);
		Cat	&operator=(Cat const &rhs);

		void	makeSound() const;
};

#endif //CAT_HPP