/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:33 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/06 13:24:08 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string& str) : _str(str) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) : _str(other._str) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        _str = other._str;
    return *this;
}

void ScalarConverter::display() const
{
	double val;
	std::stringstream ss(_str);
	
	if (_str == "-inff" || _str == "-inf")
		val = -INFINITY;
	else if (_str == "+inff" || _str == "inff" || _str == "+inf" || _str == "inf")
		val = INFINITY;
	else
	{
		if (_str.back() == 'f')
		{
			ss.str("");
			ss << _str.substr(0, _str.size() - 1);
		}
		if (!(ss >> val))
			val = NAN;
		else
        {
            std::string remaining;
            if (ss >> remaining)
                val = NAN;
        }
	}

	printAsChar(val);
	printAsInt(val);
	printAsFloat(val);
	printAsDouble(val);
}

void ScalarConverter::printAsChar(double val) const
{
	if (ScalarConverter::isNan(val) || ScalarConverter::isInf(val))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(val);

		if (val < -128 || val > 127 || c < 32 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else if (!c && _str != "0")
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
}

void ScalarConverter::printAsInt(double val) const
{
	int i = static_cast<int>(val);

	if (val < INT_MIN || val > INT_MAX || ((val - static_cast<double>(i)) != 0 && val == INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printAsFloat(double val) const
{
	float f = static_cast<float>(val);

	if (ScalarConverter::isNan(f))
		std::cout << "float: nanf" << std::endl;
	else if (ScalarConverter::isInf(f) && f > 0)
		std::cout << "float: inff" << std::endl;
	else if (ScalarConverter::isInf(f) && f < 0)
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printAsDouble(double val) const
{
	if (ScalarConverter::isNan(val))
		std::cout << "double: nan" << std::endl;
	else if (ScalarConverter::isInf(val) && val > 0)
		std::cout << "double: inf" << std::endl;
	else if (ScalarConverter::isInf(val) && val < 0)
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

bool ScalarConverter::isNan(double val) const
{
	volatile double d = val;
	return d != d;
}

bool ScalarConverter::isInf(double val) const
{
	return val == INFINITY || val == -INFINITY;
}
