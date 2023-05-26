/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:21:34 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:29:46 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(const Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (_weapon != NULL)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
}

HumanB::~HumanB() {}