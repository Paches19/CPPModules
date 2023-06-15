/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 14:07:15 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	int num;
}		Data;

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data myData = {42};

	std::cout << "Original address: " << &myData << std::endl;

	uintptr_t serialized = serialize(&myData);
	std::cout << "Serialized address: " << serialized << std::endl;

	Data* deserialized = deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;

	if (deserialized == &myData)
	{
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "Original Value: " << myData.num << std::endl;
		std::cout << "Deserialized Value: " << deserialized->num << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed!" << std::endl;
		std::cout << "Original Value: " << myData.num << std::endl;
		std::cout << "Deserialized Value: " << deserialized->num << std::endl;
	}

	return 0;
}
