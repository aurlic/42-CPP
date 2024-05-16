/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:27:24 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/16 17:35:25 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* k = new WrongCat();
	std::cout << "-----------------------------------------" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	std::cout << "-----------------------------------------" << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	k->makeSound();

	std::cout << "-----------------------------------------" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	
	return 0;
}