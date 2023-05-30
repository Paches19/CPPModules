/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/30 18:13:19 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Adpachec");

	clapTrap.attack("Enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.attack("Enemy");
	clapTrap.takeDamage(15);
	clapTrap.takeDamage(15);
	clapTrap.beRepaired(2);
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");
	clapTrap.attack("Enemy");

	return 0;
}
