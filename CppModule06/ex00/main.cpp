/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 14:07:15 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string literal = argv[1];
	ScalarConverter converter;

	converter.convertToChar(literal);
	converter.convertToInt(literal);
	converter.convertToFloat(literal);
	converter.convertToDouble(literal);

	return 0;
}