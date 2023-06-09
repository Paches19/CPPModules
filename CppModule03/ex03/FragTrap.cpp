/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:21:25 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 12:33:33 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " created by copy!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " created with name!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->getName() << " created by copy!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << this->getName() << " assigned with FragTrap "
			<< other.getName() << std::endl;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap: " << this->getName() << " high five!" << std::endl;
}
