/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:27:24 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/17 14:53:44 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <limits>

// int main()
// {
// 	// Dog basic;
// 	// {
// 	// 	Dog tmp = basic;
// 	// }
// 	Animal	*tab[100];
// 	int		size = 0;

// 	while (true) {
// 		std::cout << "Please enter the array size: ";
// 		if (std::cin >> size) {
// 			break;
// 		}
// 		else {
// 			std::cin.clear();
// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 			std::cout << "Invalid input. Please enter an integer.\n";
// 		}
// 	}
// 	for (int i = 0; i < size; ++i) {
// 		if (i < size / 2) {
// 			tab[i] = new Dog();
// 		}
// 		else if (i >= size / 2) {
// 			tab[i] = new Cat();
// 		}
// 	}

// 	for (int i = 0; i < size; ++i) {
// 		delete tab[i];
// 	}

// 	return (0);
// }

int main(void) 
{
    std::cout << "---------------------HEAP---------------------" << std::endl;

    const Animal*    cat = new Cat();
    const Animal*    dog = new Dog();
    const Animal*    animal = new Animal();

    delete    cat;
    delete    dog;
    delete    animal;

    std::cout << "--------------------STACK---------------------" << std::endl;

    Cat    stack_cat;
    Cat    operator_cat = stack_cat;
    Cat    copy_cat(stack_cat);

    Dog    stack_dog;
    Dog    oeprator_dog = stack_dog;
    Dog    copy_dog(stack_dog);

    std::cout << "---------------------ARRAY--------------------" << std::endl;

    int        len = 10;
    int        k = 0;
    Animal    *tab[len];

    while (k < (len / 2))
    {
        tab[k] = new Dog();
        k++;
    }
    while (k < len)
    {
        tab[k] = new Cat();
        k++;
    }
    while (--k >= 0)
        delete tab[k];
    std::cout << "---------------------LAST--------------------" << std::endl;
    return (0);
}