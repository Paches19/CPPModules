/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:43 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:30:03 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}

Weapon::~Weapon() {}
