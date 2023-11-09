/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/09 16:21:35 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

int main()
{
	Serializer *myData = Serializer::crearSerializer(42);

	std::cout << "Original address: " << myData << std::endl;

	uintptr_t serialized = myData->serialize(myData);
	std::cout << "Serialized address: " << serialized << std::endl;

	Serializer *deserialized = myData->deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;

	Serializer *badDeserialized = myData->deserialize(165161651651);
    std::cout << "Bad deserialized address: " << badDeserialized << std::endl;

	if (deserialized == myData)
	{
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "Original Value: " << myData->getNum() << std::endl;
		std::cout << "Deserialized Value: " << deserialized->getNum() << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed!" << std::endl;
		std::cout << "Original Value: " << myData->getNum() << std::endl;
		std::cout << "Deserialized Value: " << deserialized->getNum() << std::endl;
	}

	std::cout << std::endl;
	if (badDeserialized == myData)
	{
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "Original Value: " << myData->getNum() << std::endl;
		std::cout << "Deserialized Value: " << badDeserialized->getNum() << std::endl;
	}
	else
		std::cout << "Deserialization failed!" << std::endl;

	delete myData;

	return 0;
}
