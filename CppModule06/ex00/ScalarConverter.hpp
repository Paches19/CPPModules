/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:56:22 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/03 10:40:19 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

class ScalarConverter
{
	private:
		std::string _str;
		
		bool isOnlyDigits(const std::string &str) const;
		
		bool isChar() const;
		bool isInt() const;
		bool isFloat() const;
		bool isDouble() const;
		void printAsChar(double val) const;
		void printAsInt(double val) const;
		void printAsFloat(double val) const;
		void printAsDouble(double val) const;

	public:
		ScalarConverter(const std::string& str);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& other);

		void display() const;
		bool isNan(double val) const;
		bool isInf(double val) const;
};

#endif