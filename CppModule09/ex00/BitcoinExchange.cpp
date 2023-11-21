/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:53:42 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/21 11:24:44 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string databaseName("data.csv");
	loadDatabase(databaseName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other) 
		_database = other._database;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(std::string& filename)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Failed to open the input file." << std::endl;
		return ;
	}

	std::string line;
	std::string date;
	std::string value;
	while (std::getline(inputFile, line))
	{
		size_t pos = line.find(',');
		if (pos != std::string::npos && pos == 10)
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 1);
			_database[date] = std::atof(value.c_str());
		}
	}
	inputFile.close();
}

void BitcoinExchange::displayOutput(std::string& filename)
{
	std::string date;
	std::string value;
		
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Failed to open the input file." << std::endl;
		return;
	}

	std::string line;
	if (!(std::getline(inputFile, line) && line == "date | value"))
		getOutput(line);

	while (std::getline(inputFile, line))
		getOutput(line);

	inputFile.close();
}

void BitcoinExchange::getOutput(std::string& line)
{
	std::string date;
	std::string value;

	size_t pos = line.find('|');
	date = line.substr(0, pos - 1);
	value = line.substr(pos + 2);

	if (isValidDate(date) && isValidValue(value))
	{
		float inputValue = std::atof(value.c_str());
		float exchangeRate = getExchangeRate(date);
		
		if (exchangeRate >= 0)
		{
			float result = exchangeRate * inputValue;
			std::cout << date << " => " << inputValue << " = " << result << std::endl;
		}
		else
			std::cerr << "Error: not a positive number." << std::endl;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	std::string format = "####-##-##";
	if (date.length() != format.length())
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;
		return false;
	}

	std::string monthStr(date.substr(5, 2));
	std::string dayStr(date.substr(8, 2));
	
	int month = std::atof(monthStr.c_str());
	int day = std::atof(dayStr.c_str());

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;
		return false;
	}
	if (day < 1 || day > 31)
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(std::string& value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && (value[0] == '-' || value[0] == '+'))
			;
		else if (!std::isdigit(value[i]))
		{
			std::cerr << "Error: Value must be a positive number in range [0-1000]. Value: " << value << std::endl;
			return false;
		}
	}
	
	float floatValue = std::atof(value.c_str());
	if (floatValue < 0)
	{
		std::cerr << "Error: Value must be positive in range [0-1000]. Value: " << value << std::endl;
		return false;
	}
	else if (floatValue > 1000)
	{
		std::cerr << "Error: Value is too large not in range [0, 1000]. Value: " << value << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::const_iterator it;
	it = _database.upper_bound(date);
	if (it == _database.begin())
		return (_database.begin()->second);
	--it;
	return it->second;
}

void BitcoinExchange::displayDatabase() const
{
	std::map<std::string, float>::const_iterator it;
	for (it = _database.begin(); it != _database.end(); ++it)
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) << it->second << std::endl;
}
