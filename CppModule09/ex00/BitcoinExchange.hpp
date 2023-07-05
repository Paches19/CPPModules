/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:51:26 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/05 11:48:41 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cmath>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		void loadDatabase(std::string& filename);
		bool isValidDate(const std::string& date);
		bool isValidValue(std::string& value);
		float getExchangeRate(const std::string& inputKey);
		int getDateDifference(const std::string& date1, const std::string& date2);
		void getOutput(std::string& line);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);

		void displayDatabase(void) const;
		void displayOutput(std::string& filename);
		float stof(std::string& value) const;
};

#endif
