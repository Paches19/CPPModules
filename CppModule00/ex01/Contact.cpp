/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:57:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/05 11:12:15 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(const std::string& _firstName, const std::string& _lastName, const std::string& _nickName,
                 const std::string& _phoneNumber, const std::string& _darkestSecret)
    : _firstName(_firstName), _lastName(_lastName), _nickName(_nickName),
      _phoneNumber(_phoneNumber), _darkestSecret(_darkestSecret) {}

std::string Contact::getFirstName(void) const 
{
    return this->_firstName;
}

std::string Contact::getLastName(void) const 
{
    return this->_lastName;
}

std::string Contact::getNickName(void) const 
{
    return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const 
{
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const 
{
    return this->_darkestSecret;
}

Contact::~Contact(void) {}