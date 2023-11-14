/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:07:46 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/14 10:53:07 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int size) : _N(size)
{
	_numbers.reserve(size);
}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

const char* Span::FullSpanException::what() const throw()
{
	return "Cannot add more numbers, maximum capacity reached\n";
}

const char* Span::EmptySpanExcepction::what() const throw()
{
	return "Cannot find span, not enough numbers\n";
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw FullSpanException();
	_numbers.push_back(number);
}

void Span::addRange(const std::vector<int>& numbers)
{
	if (_numbers.size() + numbers.size() > _N)
		throw FullSpanException();
	_numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw EmptySpanExcepction();

	int span;
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); i++)
	{
		span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw EmptySpanExcepction();

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}

void Span::printSpan() const
{
	if (_numbers.size() <= 0)
		std::cerr << "Not enough members to print. Empty vector" << std::endl;
	else
	{	
		std::cout << "Span: ";
		for (size_t i = 0; i < _numbers.size(); ++i)
			std::cout << _numbers[i] << " ";
		std::cout << std::endl;
	}
}
