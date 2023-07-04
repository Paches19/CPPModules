/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:12:34 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/04 16:47:12 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: No input file especified" << std::endl;
		return 1;
	}

	std::string filename = argv[1];

    BitcoinExchange bitcoinExchange;
    bitcoinExchange.displayOutput(filename);

    return 0;
}
