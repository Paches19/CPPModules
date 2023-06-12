/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:20:44 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/12 12:38:40 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::stringstream str;

	for (int i = 0; i < 100; i++)
	{
		str << "Idea " << i + 1;
		this->ideas[i] = str.str();
	}
    std::cout << "A Brain has been created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain created by copy" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
        	this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain created by assignment operator" << std::endl;
	return *this;
}

std::string* Brain::getIdeas( void )
{
	return this->ideas;
}
