/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:53:27 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 13:16:27 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    this->_name = "Default";
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergy(100);
	this->FragTrap::setAttackDamage(30);
    std::cout << "DiamondTrap " << this->_name << " created by default!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergy(100);
	this->FragTrap::setAttackDamage(30);
    std::cout << "DiamondTrap " << this->_name << " created with name!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other)
{
    this->_name = other._name;
    std::cout << "DiamondTrap " << this->_name << " created by copy!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " destroyed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
		this->_name = other._name;
		this->FragTrap::setHitPoints(other.FragTrap::getHitPoints());
		this->ScavTrap::setEnergy(other.ScavTrap::getEnergyPoints());
		this->FragTrap::setAttackDamage(other.FragTrap::getAttackDamage());
		std::cout << "DiamondTrap " << this->_name << " assigned with DiamondTrap "
			<< other._name << std::endl;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->_name << ", also known as ClapTrap " << this->FragTrap::getName() << std::endl;
}
