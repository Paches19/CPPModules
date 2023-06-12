/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:59:14 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/12 13:43:55 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	const int size = 10;
	Animal* animals[size];

	for (int it = 0; it < size; it++)
	{
		if (it < size / 2)
			animals[it] = new Dog();
		else
			animals[it] = new Cat();
	}

	for (int it = 0; it < size; it++)
	{
		std::cout << animals[it]->getType() << " sound : ";
		animals[it]->makeSound();
	}

	for (int it = 0; it < size; it++)
		delete animals[it];

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;
	
	Dog* dog2 = new Dog();
	Dog* dog3 = new Dog(*dog2);

	delete(dog2);
	delete(dog3);
	
	Cat *cat2 = new Cat();
	Cat cat3 = *cat2;
	Cat cat4;

	cat3 = cat4;
	delete(cat2);
	
	return 0;
}

