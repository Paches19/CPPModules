/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:56:22 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/09 12:16:11 by adpachec         ###   ########.fr       */
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
		double		val;

		bool isOnlyDigits(const std::string &str) const;
		
		bool isChar() const;
		bool isInt() const;
		bool isFloat() const;
		bool isDouble() const;
		void printAsChar();
		void printAsInt();
		void printAsFloat();
		void printAsDouble();

	public:
		ScalarConverter(const std::string& str);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& other);

		void display();
		bool isNan() const;
		bool isInf() const;
};

#endif