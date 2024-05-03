/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:54:33 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 16:46:40 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::init()
{
	std::cout << "\033[1;4mPlease enter your contact's first name :\033[0m" << std::endl;
	std::cin >> this->_firstName;
	std::cout << "\033[1;4mPlease enter your contact's last name :\033[0m" << std::endl;
	std::cin >> this->_lastName;
	std::cout << "\033[1;4mPlease enter your contact's nickname :\033[0m" << std::endl;
	std::cin >> this->_nickName;
	std::cout << "\033[1;4mPlease enter your contact's phone number :\033[0m" << std::endl;
	std::cin >> this->_phoneNumber;
	std::cout << "\033[1;4mPlease enter your contact's darkest secret :\033[0m" << std::endl;
	std::cin >> this->_secret;
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