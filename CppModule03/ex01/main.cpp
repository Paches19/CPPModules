/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 12:11:32 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap adpachec("Adpachec");
	ScavTrap enemy("Enemy");

    adpachec.attack("Enemy");
	enemy.takeDamage(20);
    adpachec.guardGate();

    ScavTrap adpachecCopy(adpachec);
    adpachecCopy.attack("Enemy");
	enemy.takeDamage(20);

    ScavTrap enemyAssignment;
    enemyAssignment = adpachecCopy;
    enemyAssignment.attack("adpachecCopy");
	adpachecCopy.takeDamage(20);
	
	return 0;
}
