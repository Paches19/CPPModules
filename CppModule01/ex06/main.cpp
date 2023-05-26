/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:47:30 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 13:36:31 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <filter>" << std::endl;
		return 0;
	}
	std::cout << "Comportamiento sin filtro: " << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "Comportamiento con filtro: " << std::endl;
	harl.filter(argv[1]);

	return 0;
}
