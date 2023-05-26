/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:31:37 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 13:34:03 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl () {}

void Harl::debug()
{
    std::cout << "DEBUG:" << std::endl
		<< "I love having extra bacon for my"
		<< " 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info()
{
    std::cout << "INFO: " << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING: " << std::endl 
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error()
{
    std::cout << "ERROR: " << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*function[4])(void) =
		{
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
		
	for(int i = -1; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*(function[i]))();
			return;
        }
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << level << std::endl;        
}

Harl::~Harl() {}