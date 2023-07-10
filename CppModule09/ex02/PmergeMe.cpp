/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:49 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/10 13:26:07 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char* argv[]) : _success(false)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input numbers provided." << std::endl;
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (!isNumber(arg))
		{
			std::cerr << "Error: Invalid argument \"" << arg
				<< "\". Only positive integers are allowed." << std::endl;
			return ;
		}
		int number = std::atoi(argv[i]);
		if (number >= 0)
		{
			_numbersDeque.push_back(number);
			_numbersList.push_back(number);
		}
		else
		{
			std::cerr << "Error: Invalid argument \"" << arg
				<< "\". Only positive integers are allowed." << std::endl;
			return ;
		}
	}
	_success = true;
}

PmergeMe::PmergeMe(std::deque<int> source) : _numbersDeque(source), _success(false){}

PmergeMe::PmergeMe(std::list<int> source) : _numbersList(source), _success(false){}

PmergeMe::PmergeMe(const PmergeMe& other) :_numbersDeque(other._numbersDeque),
	_numbersList(other._numbersList), _success(other._success) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_numbersDeque = other._numbersDeque;
		_numbersList = other._numbersList;
		_success = other._success;
	}
	return *this;
}

void PmergeMe::sortAndPrint()
{
	if (!_success)
		return ;
	clock_t start, end;
	double timeToExecute;

	printContainer(_numbersDeque, "std::deque", 1);
	start = clock();
	mergeInsertSort(_numbersDeque);
	end = clock();
	timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	printContainer(_numbersDeque, "std::deque", 0);
	std::cout << "Time to process a range of " << _numbersDeque.size() <<
		" elements with std::deque: " << timeToExecute << " s\n";
	std::cout << std::endl;

	printContainer(_numbersList, "std::list", 1);
	start = clock();
	mergeInsertSort(_numbersList);
	end = clock();
	timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	printContainer(_numbersList, "std::list", 0);
	std::cout << "Time to process a range of " << _numbersList.size() << " elements with std::list: " << timeToExecute << " s\n";
}

template<typename T>
void PmergeMe::merge(T& left, T& right)
{
	T result;
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}
	left = result;
}

template<typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	if (container.size() <= 1)
		return;

	typename T::iterator middle = container.begin();
	std::advance(middle, container.size() / 2);
	
	T left(container.begin(), middle);
	T right(middle, container.end());
	
	mergeInsertSort(left);
	mergeInsertSort(right);
	
	merge(left, right);
	
	container = left;
}

template<typename T>
void PmergeMe::printContainer(T& container, const std::string& name, bool init)
{
	if (init)
   		std::cout << "Before sorting with " << name << ": ";
	else
		std::cout << "After sorting with " << name << ": ";
    std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

bool PmergeMe::isNumber(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}
