/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:38:17 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/25 20:24:34 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	zombie1 = newZombie("HeapZombie");
	
	Zombie	zombie2("StackZombie");
	
	randomChump("RandomZombie");
	
	delete zombie1;

	return 0;
}
