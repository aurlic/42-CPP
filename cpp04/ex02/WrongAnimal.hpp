/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:19:19 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:30:48 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();

		WrongAnimal(WrongAnimal const &other);
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		void		makeSound() const; //not virtual so static
		std::string			getType() const;
};

#endif //WRONGANIMAL_HPP