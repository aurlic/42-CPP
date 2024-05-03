/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:48:22 by aurlic            #+#    #+#             */
/*   Updated: 2024/05/03 16:44:15 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];

	public:
		PhoneBook();
		~PhoneBook();

		void	launch(void) const;
		void	addContact(void);
		void	printContacts(void) const;
		void	search() const;
};

#endif