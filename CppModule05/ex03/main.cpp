/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/14 12:46:24 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void )
{
	try
	{
		Bureaucrat adpachec("adpachec", 1);
		std::cout << adpachec << std::endl;
		PresidentialPardonForm Pardon("adgutier");
		adpachec.executeForm(Pardon);
		std::cout << std::endl;
		adpachec.signForm(Pardon);
		adpachec.executeForm(Pardon);
		std::cout << std::endl << std::endl;
	}
	catch( std::exception & e)
	{
		std::cout << e.what();
	}

	try
	{
		Bureaucrat adpachec("adpachec", 40);
		std::cout << adpachec << std::endl;
		Intern becario;
		AForm *form;
		form = becario.makeForm("robotomy request", "adgutier");
		adpachec.executeForm(*form);
		std::cout << std::endl;
		adpachec.signForm(*form);
		adpachec.executeForm(*form);
		delete (form);
		std::cout << std::endl << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat adpachec("adpachec", 40);
		std::cout << adpachec << std::endl;
		Intern becario;
		AForm *form;
		form = becario.makeForm("alicatar baño", "adgutier");
		if (form)
		{
			adpachec.executeForm(*form);
			std::cout << std::endl;
			adpachec.signForm(*form);
			adpachec.executeForm(*form);
			std::cout << std::endl;
		}
		delete (form);
		std::cout << std::endl << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}
	return 0;
}