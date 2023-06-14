/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:33 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 14:33:52 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
			;
	return *this;
}

const char* ScalarConverter::ConversionException::what() const throw()
{
	return "impossible\n";
}

void ScalarConverter::convertToChar(const std::string& literal) const
{
	char value = literal[0];

	std::cout << "char: ";

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		throw ConversionException();
		
	if (literal.length() != 1 || !std::isprint(value))
		std::cout << " Non displayable" << std::endl;
	else
		std::cout << value << std::endl;
}

void ScalarConverter::convertToInt(const std::string& literal) const
{
	std::cout << "int: ";
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		throw ConversionException();
	try
	{
		int value = std::atoi(literal.c_str());;
		std::cout << value << std::endl;
	}
	catch
		std::cout << e.what() << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& literal) const
{
	std::cout << "float: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inff" << std::endl;
	else if (literal == "+inff" || literal == "+inff")
		std::cout << "+inff" << std::endl;
	else if (literal == "nan" || literal == "nanf")
		std::cout << "nanf" << std::endl;

	std::istringstream iss(literal);
	float value = 0.0f;
	if (!(iss >> value))
	{
		throw ConversionException();
	}
	std::cout << value << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& literal) const
{
	std::cout << "double: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inf" << std::endl;
	else if (literal == "+inff" || literal == "+inff")
		std::cout << "+inf" << std::endl;
	else if (literal == "nan" || literal == "nanf")
		std::cout << "nan" << std::endl;

	std::istringstream iss(literal);
	double value = 0.0f;
	if (!(iss >> value))
	{
		throw ConversionException();
	}
	std::cout << value << std::endl;
}
