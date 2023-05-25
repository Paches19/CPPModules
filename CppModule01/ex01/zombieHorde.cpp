/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:27:16 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/25 20:39:45 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "iostream"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;

	if (N <= 0)
	{
		std::cout << "The number of zombies must be >= 0" << std::endl;
	}

	horde = new Zombie[N];
	
	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name);
		horde[i].announce();
	}

	return horde;
}
