/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:18:59 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 12:52:50 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& other)
{
	if (this == &other)
		return;
	*this = other;
}

Intern::~Intern(void) {}

Intern& Intern::operator=(const Intern& other)
{
	if (this  == &other)
		;
	return *this;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form: Form requested doesn't exist \n";
}
				
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;

	for (i = -1; i < 3; ++i)
	{
		if (formNames[i] == formName)
			break ;
	}

    switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		case 3:
			throw UnknownFormException();
	}

	return NULL;
}
