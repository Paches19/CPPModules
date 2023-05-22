/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:50:32 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/22 13:55:54 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() 
{
	PhoneBook phoneBook;
	std::string command;
	
	std::cout << "Enter the command you want to run" << std::endl;
	std::cout << "ADD: for adding a contact to your agenda" << std::endl;
	std::cout << "SEARCH: for searching a contact in your agenda" << std::endl;
	std::cout << "EXIT: for closing your agenda" << std::endl << std::endl;
	while (std::getline(std::cin, command)) 
	{
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
		if(std::cin.fail())
			return 1;
    }
    return 0;
}
