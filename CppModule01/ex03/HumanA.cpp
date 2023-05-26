/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:16:09 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:47 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() {}
