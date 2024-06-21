/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:07:47 by aurlic            #+#    #+#             */
/*   Updated: 2024/06/21 10:58:01 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	/* ************************************************************************** */
	std::cout << "*------------------------------*" << std::endl;
	std::cout << "| pop, top, size               |" << std::endl;
	std::cout << "*------------------------------*" << std::endl;
	std::cout << "| Top element: " << mstack.top() << "               |" << std::endl;
	std::cout << "| Stack size: " << mstack.size() << "                |" << std::endl;

	mstack.pop();

	std::cout << "| Top element after pop: " << mstack.top() << "     |" << std::endl;
	std::cout << "| Stack size after pop: " << mstack.size() << "      |" << std::endl;
	std::cout << "*------------------------------*" << std::endl;
	/* ************************************************************************** */

	std::cout << "      ~~~      " << std::endl;

	/* ************************************************************************** */
	std::cout << "*--------------------------------------------*" << std::endl;
	std::cout << "| listing elements                           |" << std::endl;
	std::cout << "*--------------------------------------------*" << std::endl;
	std::cout << "| Stack elements (iterator): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "        |"<< std::endl;

	std::cout << "| Stack elements (reverse iterator): ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << "|" << std::endl;
	std::cout << "*--------------------------------------------*" << std::endl;
	/* ************************************************************************** */

	std::cout << "      ~~~      " << std::endl;

	/* ************************************************************************** */
	std::cout << "*-------------------------------------------------------*" << std::endl;
	std::cout << "| incrementing elements                                 |" << std::endl;
	std::cout << "*-------------------------------------------------------*" << std::endl;
	std::cout << "| Incrementing each element by 1 using iterator.        |" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		*it += 1;
	}
	std::cout << "| Stack elements after incrementing (iterator): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "|"<< std::endl;
	
	std::cout << "| Stack elements (reverse iterator): ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << "           |" << std::endl;
	std::cout << "*-------------------------------------------------------*" << std::endl;
	/* ************************************************************************** */

	std::cout << "      ~~~      " << std::endl;

	/* ************************************************************************** */
	MutantStack<int> emptyStack;
	std::cout << "*-------------------------------------*" << std::endl;
	std::cout << "| Iterating over an empty stack:      |";
	for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it) {
		std::cout << *it << " "; // Should not output anything
	}
	std::cout << std::endl << "| Done (no output expected)           |" << std::endl;
	std::cout << "*-------------------------------------*" << std::endl;

	/* ************************************************************************** */
	
	return 0;
}