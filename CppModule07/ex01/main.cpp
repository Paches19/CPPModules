/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/19 11:23:34 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void print(const T& value)
{
    std::cout << value << " ";
}

template<typename T>
void increment(T& value)
{
    value++;
}

int main()
{
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Char array: ";
	iter(charArray, 5, print<char>);
	std::cout << std::endl;
	
	int intArray[] = {1, 2, 3, 4, 5};

	std::cout << "Int array: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	iter(intArray, 5, increment<int>);
	std::cout << "Int array: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	return 0;
}
