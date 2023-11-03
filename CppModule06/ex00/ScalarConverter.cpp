/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:33 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/03 11:26:26 by adpachec         ###   ########.fr       */
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

bool ScalarConverter::isOnlyDigits(const std::string &str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			;
		else if (!isdigit(str[i]))
			return false;
	}

	return true;
}

bool ScalarConverter::isChar() const
{
	if (_str.length() == 1 && _str[0] >= 32 && _str[0] <= 126)
		return true;
	return false;
}

bool ScalarConverter::isInt() const
{
	if (isOnlyDigits(_str))
		return true;
	return false;
}

bool ScalarConverter::isFloat() const
{
	if (_str.find('.') != std::string::npos && _str[_str.size() - 1] == 'f')
		return true;
	return false;
}

bool ScalarConverter::isDouble() const
{
	if (_str.find('.') != std::string::npos && _str[_str.size() - 1] != 'f')
		return true;
	return false;
}

void ScalarConverter::display() const
{
	double val = 0;
	std::stringstream ss(_str);

	if (_str == "-inff" || _str == "-inf")
		val = -INFINITY;
	else if (_str == "+inff" || _str == "inff" || _str == "+inf" || _str == "inf")
		val = INFINITY;
	else
	{
		if (isFloat())
		{
			ss.str("");
			ss << _str.substr(0, _str.size() - 1);
		}

		if (isChar())
			val = static_cast<double>(static_cast<int>(_str[0]));
		else if (isInt())
			val = static_cast<double>(atof(_str.c_str()));
		else if (isFloat())
			val = static_cast<double>(atof(_str.c_str()));
		else if (isDouble())
			val = (atof(_str.c_str()));
		else if (!(ss >> val))
			val = NAN;
	}
	printAsChar(val);
	printAsInt(val);
	printAsFloat(val);
	printAsDouble(val);
}

void ScalarConverter::printAsChar(double val) const
{
	if (isNan(val) || isInf(val))
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
	if (isInf(val) && val > 0)
		std::cout << "int: inf" << std::endl;
	else if (isInf(val) && val < 0)
		std::cout << "int: -inf" << std::endl;
	else if (val < INT_MIN || val > INT_MAX || isNan(val))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::printAsFloat(double val) const
{
	float f = static_cast<float>(val);

	if (isNan(f))
		std::cout << "float: nanf" << std::endl;
	else if (isInf(f) && f > 0)
		std::cout << "float: inff" << std::endl;
	else if (isInf(f) && f < 0)
		std::cout << "float: -inff" << std::endl;
	else if (val > __FLT_MAX__ || val < -__FLT_MIN__ || (val != 0 && std::abs(val) < __FLT_MIN__))
        std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printAsDouble(double val) const
{
	if (isNan(val))
		std::cout << "double: nan" << std::endl;
	else if (isInf(val) && val > 0)
		std::cout << "double: inf" << std::endl;
	else if (isInf(val) && val < 0)
		std::cout << "double: -inf" << std::endl;
	else if (val == HUGE_VAL || val == -HUGE_VAL)
        std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

bool ScalarConverter::isNan(double val) const
{
	if (val == NAN)
		return true;
	volatile double d = val;
	return d != d;
}

bool ScalarConverter::isInf(double val) const
{
	return val == INFINITY || val == -INFINITY;
}