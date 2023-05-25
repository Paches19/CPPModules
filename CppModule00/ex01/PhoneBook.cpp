/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:56:31 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/25 11:33:09 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook(void) : contactCount(0), oldestContact(0) {}

std::string PhoneBook::setFirstName(void)
{
	std::string firstName;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	if (!firstName.empty())
		return firstName;
	while (firstName.empty())
	{
		std::cout << "First name cannot be empty. Enter first name: ";
		if (!std::getline(std::cin, firstName))
		{
			std::cerr << "ERROR: Fatal Input Error" << std::endl;
			return "";
		}
	}
	return firstName;
}

std::string PhoneBook::setLastName(void)
{
	std::string lastName;

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	if (!lastName.empty())
		return lastName;
	while (lastName.empty())
	{
		std::cout << "last name cannot be empty. Enter last name: ";
		if (!std::getline(std::cin, lastName))
		{
			std::cerr << "ERROR: Fatal Input Error" << std::endl;
			return "";
		}
	}
	return lastName;
}

std::string PhoneBook::setNickName(void)
{
	std::string nickName;

	std::cout << "Enter nick name: ";
	std::getline(std::cin, nickName);
	if (!nickName.empty())
		return nickName;
	while (nickName.empty())
	{
		std::cout << "nick name cannot be empty. Enter nick name: ";
		if (!std::getline(std::cin, nickName))
		{
			std::cerr << "ERROR: Fatal Input Error" << std::endl;
			return "";
		}
	}
	return nickName;
}

std::string PhoneBook::setPhoneNumber(void)
{
	std::string phoneNumber;

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	if (!phoneNumber.empty())
		return phoneNumber;
	while (phoneNumber.empty())
	{
		std::cout << "phone number cannot be empty. Enter phone number: ";
		if (!std::getline(std::cin, phoneNumber))
		{
			std::cerr << "ERROR: Fatal Input Error" << std::endl;
			return "";
		}
	}
	return phoneNumber;
}

std::string PhoneBook::setDaarkestSecret(void)
{
	std::string darkestSecret;

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (!darkestSecret.empty())
		return darkestSecret;
	while (darkestSecret.empty())
	{
		std::cout << "darkest secret cannot be empty. Enter darkest secret: ";
		if (!std::getline(std::cin, darkestSecret))
		{
			std::cerr << "ERROR: Fatal Input Error" << std::endl;
			return "";
		}
	}
	return darkestSecret;
}

void PhoneBook::addContact(void) 
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	if (contactCount == 8)
        std::cout << "The PhoneBook is full. The oldest contact will be replaced" << std::endl;
	
	firstName = setFirstName();
	if (firstName.empty())
		return ;
	lastName = setLastName();
	if (lastName.empty())
		return ;
	nickName = setNickName();
	if (nickName.empty())
		return ;
	phoneNumber = setPhoneNumber();
	if (phoneNumber.empty())
		return ;
	darkestSecret = setDaarkestSecret();
	if (darkestSecret.empty())
		return ;

    if (contactCount == 8)
	{
		contacts[oldestContact] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
		if (oldestContact == 7)
			oldestContact = 0;
		else
			oldestContact++;
	}
	else
        contacts[contactCount++] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	std::cout << std::endl << "Enter the command you want to run" << std::endl;
}

void PhoneBook::printContacts(void) const
{
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "|    Index    |  First Name |  Last Name  |  Nickname   |" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	
	for (int i = 0; i < contactCount; ++i) 
	{
		std::cout << "|  " << std::setw(10) << i << " |";
		std::cout << "  " << std::setw(10) << (this->contacts[i].getFirstName().length() > 10 ?
			this->contacts[i].getFirstName().substr(0, 9) + "." : this->contacts[i].getFirstName()) << " |";
		std::cout << "  " << std::setw(10) << (this->contacts[i].getLastName().length() > 10 ?
			this->contacts[i].getLastName().substr(0, 9) + "." : this->contacts[i].getLastName()) << " |";
		std::cout << "  " << std::setw(10) << (this->contacts[i].getNickName().length() > 10 ?
			this->contacts[i].getNickName().substr(0, 9) + "." : this->contacts[i].getNickName()) << " |" << std::endl;
	}

	std::cout << "---------------------------------------------------------" << std::endl;
}

void PhoneBook::searchContacts(void) const 
{
	printContacts();
	if (contactCount > 0) 
	{
		int index;
		
		std::cout << "Enter the index of the contact to display: ";
		std::cin >> index;
		
		if (std::cin >> index && !std::cin.fail())
		{
			std::cin.ignore();
			if (index >= 0 && index < contactCount) 
			{
				std::cout << "---------------------------------------------------------" << std::endl;
				std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
				std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
				std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
				std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
			}
			else
			{
				std::cin.clear();
				std::cout << "Invalid index. No contact found." << std::endl;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index. No contact found." << std::endl;
		}
	} 
	else
		std::cout << "No contacts in the phone book." << std::endl;
	std::cout << std::endl << "Enter the command you want to run" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}