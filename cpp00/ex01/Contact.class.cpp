/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:54:33 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/06 15:49:59 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::_alnumStr(std::string str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		{
			if (!std::isalnum(*it))
				return (false);
		}
	return (true);
}

std::string	Contact::_checkInput(const std::string prompt) const
{
	std::string	input;

	while (!std::cin.eof() && true)
	{
		std::cout << "\033[1;4m" << prompt << "\033[0m" << std::endl;
		std::getline(std::cin >> std::ws, input);
		if (_alnumStr(input))
			break ;
		std::cout << "Invalid input, must be alpha numeric" << std::endl;
	}
	return (input);
}

void	Contact::init()
{
	this->_firstName = _checkInput("Please enter your contact's first name :");
	this->_lastName = _checkInput("Please enter your contact's last name: ");
    this->_nickName = _checkInput("Please enter your contact's nickname: ");
    this->_phoneNumber = _checkInput("Please enter your contact's phone number: ");
    this->_secret = _checkInput("Please enter your contact's darkest secret: ");
	std::cout << "                 ~~~~~~                 " << std::endl;
}

void	Contact::setIndex(int i)
{
	this->index = i;
}

std::string	Contact::_setLen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::displayBook(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_setLen(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_setLen(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_setLen(this->_nickName);
	std::cout << "|" << std::endl;
}

void	Contact::displayChoice(int i) const
{
	std::cout << "Index : " << i << std::endl;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_secret << std::endl << std::endl;
}