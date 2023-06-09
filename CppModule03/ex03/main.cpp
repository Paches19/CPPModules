/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 13:12:09 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap adpachec("adpachec");
	DiamondTrap enemy("enemy");

	adpachec.whoAmI();
	enemy.whoAmI();

	adpachec.attack("enemy");
	enemy.takeDamage(adpachec.getAttackDamage());

	adpachec.highFivesGuys();
	enemy.guardGate();

	adpachec.beRepaired(20);
	enemy.beRepaired(10);

	return 0;
}
