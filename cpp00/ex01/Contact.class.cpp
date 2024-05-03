/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:54:33 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 15:30:07 by aurlic           ###   ########.fr       */
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
	std::cout << "Please enter your contact's first name :" << std::endl;
	std::cin >> this->_firstName;
	std::cout << "Please enter your contact's last name :" << std::endl;
	std::cin >> this->_lastName;
	std::cout << "Please enter your contact's nickname :" << std::endl;
	std::cin >> this->_nickName;
	std::cout << "Please enter your contact's phone number :" << std::endl;
	std::cin >> this->_phoneNumber;
	std::cout << "Please enter your contact's darkest secret :" << std::endl;
	std::cin >> this->_secret;
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

void	Contact::display(int index) const
{
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_setLen(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_setLen(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_setLen(this->_nickName);
	std::cout << std::endl;
}