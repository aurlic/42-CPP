/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:52:03 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 15:22:38 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		int			index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_secret;

		std::string	_setLen(std::string str) const;

	public:
		Contact();
		~Contact();
		
		void	init(void);
		void	display(int i) const;
		void	setIndex(int i);
};

#endif