/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:56:22 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 14:21:08 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>

class ScalarConverter
{
	public:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);
		
		ScalarConverter& operator=(const ScalarConverter& other);

		class ConversionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void convertToChar(const std::string& literal) const;
		void convertToInt(const std::string& literal) const;
		void convertToFloat(const std::string& literal) const;
		void convertToDouble(const std::string& literal) const;
};

#endif