/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:30:54 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 12:32:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created by default!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created with name!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other.getName()), _hitPoints(other.getHitPoints()),
	_energyPoints(other.getEnergyPoints()), _attackDamage(other.getAttackDamage())
{
	std::cout << "ClapTrap " << this->_name << " created by copy!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap " << this->_name << " assigned with ClapTrap "
		<< other.getName() << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return *this;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		std::cout << this->_energyPoints << " energy points remaining." << std::endl;
	}
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has no hit points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (amount >= (unsigned int)(this->_hitPoints))
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage. " << std::endl
				<< this->_hitPoints << " hit points remaining." << std::endl;
	} 
	else
		std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points. " << std::endl
				<< this->_hitPoints << " hit points remaining." << std::endl;
	}
	else 
		std::cout << "ClapTrap " << this->_name << " can't be repaired as it has no energy points!" << std::endl;
}

void ClapTrap::setName(std::string &name)
{
	this->_name = name;
}
		
void ClapTrap::setHitPoints(unsigned int hp)
{
	this->_hitPoints = hp;
}
		
void ClapTrap::setEnergy(unsigned int energy)
{
	this->_energyPoints = energy;
}

void ClapTrap::setAttackDamage(unsigned int attack_damage)
{
	this->_attackDamage = attack_damage;
}
