/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:09:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/22 14:06:12 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
	private:
		Contact contacts[8];
		int contactCount;
		int oldestContact;

		std::string setFirstName();
		std::string setLastName();
		std::string setNickName();
		std::string setPhoneNumber();
		std::string setDaarkestSecret();
		void printContacts() const;
};

#endif
