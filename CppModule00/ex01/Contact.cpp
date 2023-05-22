/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:57:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/22 13:47:46 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName,
                 const std::string& phoneNumber, const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickName(nickName),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

std::string Contact::getFirstName() const 
{
    return this->firstName;
}

std::string Contact::getLastName() const 
{
    return this->lastName;
}

std::string Contact::getNickName() const 
{
    return this->nickName;
}

std::string Contact::getPhoneNumber() const 
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const 
{
    return this->darkestSecret;
}
