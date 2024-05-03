/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:47:13 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 16:44:22 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::launch(void) const
{
	std::cout << std::endl;
	std::cout << "       \x1b[1;4;33mWelcome to your phonebook\x1b[0m" << std::endl;
	std::cout << " ______________________________________" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "|    Type \x1b[1;33mADD\x1b[0m to add a new contact     |" << std::endl;
	std::cout << "|                 ----                 |" << std::endl;
	std::cout << "|  Type \x1b[1;33mSEARCH\x1b[0m to search for a contact |" << std::endl;
	std::cout << "|                 ----                 |" << std::endl;
	std::cout << "|   Type \x1b[1;33mEXIT\x1b[0m to leave your phonebook  |" << std::endl;
	std::cout << "*______________________________________*" << std::endl << std::endl;
	std::cout << "                 ~~~~~~                 " << std::endl;
}

void	PhoneBook::addContact(void)
{
	static int	i;

	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const
{
	std::cout << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << "|     INDEX|  1ST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].displayBook(i);
	std::cout << "*-------------------------------------------*" << std::endl;
}

void	PhoneBook::search() const
{
	int	i = -1;

	this->printContacts();
	std::cout << "Please select index of the contact to display : ";
	std::cin >> i;
	while (i < 0 || i > 8)
	{
		std::cout << "Invalid index, please retry :";
		std::cin >> i;
	}
	this->_contacts[i].displayChoice(i);
}
