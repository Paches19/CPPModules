/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:38:17 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/25 19:52:58 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	zombie1;
	Zombie	zombie2("StackZombie");

	zombie1 = newZombie("HeapZombie");
	zombie1->announce();
	
	zombie2.announce();
	
	randomChump("RandomZombie");
	
	delete zombie1;

	return 0;
}
