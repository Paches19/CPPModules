/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:18:45 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:35 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->_brain = new Brain();
    std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(Dog& other) : Animal(other)
{
	std::cout << "Dog created by copy" << std::endl;
	this->_brain = NULL;
	*this = other;
}

Dog::~Dog()
{
	delete(this->_brain);
    std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(Dog& other)
{
	if (this == &other)
	{
		std::cout << "Cat created by assignment operator" << std::endl;
		return *this;
	}

	this->type = other.type;
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(other._brain[0]);
	std::cout << "Dog created by assignment operator" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof woof!!" << std::endl;
}
