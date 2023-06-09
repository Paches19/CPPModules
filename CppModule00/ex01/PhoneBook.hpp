/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:09:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/05 11:14:33 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8];
		int contactCount;
		int oldestContact;

		std::string setFirstName(void);
		std::string setLastName(void);
		std::string setNickName(void);
		std::string setPhoneNumber(void);
		std::string setDaarkestSecret(void);
		void printContacts(void) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(void);
		void searchContacts(void) const;
};

#endif
