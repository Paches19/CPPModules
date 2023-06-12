/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:25:12 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:26 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain();
    std::cout << "A Cat has been created" << std::endl;
}

Cat::Cat(Cat& other) : Animal(other)
{
	std::cout << "Cat created by copy" << std::endl;
	this->_brain = NULL;
	*this = other;
}

Cat::~Cat()
{
	delete(this->_brain);
    std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(Cat& other)
{
	if (this == &other)
	{
		std::cout << "Cat created by assignment operator" << std::endl;
		return *this;
	}

	this->type = other.type;
	if (this->_brain)
		delete (this->_brain);
	this->_brain =  new Brain(*other._brain);
	std::cout << "Cat created by assignment operator" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meeeoowww!!" << std::endl;
}
