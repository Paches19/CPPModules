/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/13 12:26:13 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> emptyArray;
	try
	{
		std::cout << "Empty Array: " << emptyArray[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << "Empty Array size: " << emptyArray.getSize() << std::endl;
	std::cout << std::endl;

	Array<int> array(5);
	std::cout << "Array size: " << array.getSize() << std::endl;
	for (unsigned int i = 0; i < array.getSize(); ++i)
		array[i] = i + 1;
	for (unsigned int i = 0; i < array.getSize(); ++i)
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;

	try
	{
		std::cout << "Array[10]: " << array[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Array<int> copiedArray(array);
	std::cout << "Copied Array size: " << copiedArray.getSize() << std::endl;
	for (unsigned int i = 0; i < array.getSize(); ++i)
		std::cout << "copiedArray[" << i << "]: " << copiedArray[i] << std::endl;
	std::cout << std::endl;
	
	copiedArray[0] = 100;
	std::cout << "Array[0]: " << array[0] << std::endl;
	std::cout << "Copied Array[0]: " << copiedArray[0] << std::endl << std::endl;

	Array<int> equalArray;
	equalArray = copiedArray;
	std::cout << "equalArray size: " << equalArray.getSize() << std::endl;
	for (unsigned int i = 0; i < array.getSize(); ++i)
		std::cout << "equalArray[" << i << "]: " << equalArray[i] << std::endl;
	std::cout << std::endl;
	
	equalArray[0] = 1;
	std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl;
	std::cout << "equalArray[0]: " << equalArray[0] << std::endl;

	return 0;
}
