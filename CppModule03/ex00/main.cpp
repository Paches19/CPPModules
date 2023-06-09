/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:29 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/09 11:20:01 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Adpachec("Adpachec");
	ClapTrap Enemy("Enemy");

	Adpachec.attack("Enemy");
	Enemy.takeDamage(5);
	Enemy.beRepaired(5);
	Enemy.attack("Adpachec");
	Adpachec.takeDamage(5);
	Enemy.attack("Adpachec");
	Adpachec.takeDamage(15);
	Enemy.attack("Adpachec");
	Adpachec.takeDamage(15);
	Adpachec.beRepaired(2);
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");
	Adpachec.attack("Enemy");

	return 0;
}
