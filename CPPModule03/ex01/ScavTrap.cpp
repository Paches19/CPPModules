/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:31:51 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 12:15:07 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergy(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergy(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName() << " destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << this->getName() << " assigned with ScavTrap "
			<< other.getName() << std::endl;
	}
    return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing "
                  << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergyPoints() - 1);
        std::cout << this->getEnergyPoints() << " energy points remaining." << std::endl;
    }
    else if (this->getEnergyPoints() <= 0)
        std::cout << "ScavTrap " << this->getName() << " has no energy points left to attack!" << std::endl;
    else
        std::cout << "ScavTrap " << this->getName() << " has no hit points left to attack!" << std::endl;
}
