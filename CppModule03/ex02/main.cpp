/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 12:29:21 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap adpachec("adpachec");
	FragTrap enemy("enemy");

	adpachec.attack("enemy");
	enemy.takeDamage(30);

	enemy.attack("adpachec");
	adpachec.takeDamage(30);

	adpachec.beRepaired(20);
	adpachec.highFivesGuys();

	FragTrap adpachecCopy(adpachec);
	adpachecCopy.attack("Enemy");
	enemy.takeDamage(30);
	
	FragTrap enemyAssignment;
	enemyAssignment = enemy;
	enemyAssignment.attack("adpachec");
	adpachec.takeDamage(20);

	return 0;
}
