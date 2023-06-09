/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 17:11:02 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat adpachec("adpachec", 40);
		std::cout << adpachec << std::endl;
		Bureaucrat jalvarad("jalvarad", 150);
		std::cout << jalvarad << std::endl;
		ShrubberyCreationForm form1("Paint");
		std::cout << form1 << std::endl << std::endl;

		adpachec.executeForm(form1);
		std::cout << std::endl;
		adpachec.signForm(form1);
		adpachec.executeForm(form1);
		jalvarad.executeForm(form1);
		std::cout << std::endl;
	}
	catch( std::exception & e)
	{
		std::cout << e.what();
	}

	try
	{
		Bureaucrat adpachec("adpachec", 40);
		std::cout << adpachec << std::endl;
		Bureaucrat jalvarad("jalvarad", 150);
		std::cout << jalvarad << std::endl;
		RobotomyRequestForm form2("Pacient");
		std::cout << form2 << std::endl << std::endl;

		adpachec.executeForm(form2);
		std::cout << std::endl;
		adpachec.signForm(form2);
		adpachec.executeForm(form2);
		jalvarad.executeForm(form2);
	}
	catch( std::exception & e)
	{
		std::cout << e.what();
	}

	try
	{
		Bureaucrat adpachec("adpachec", 1);
		std::cout << std::endl << adpachec << std::endl;
		Bureaucrat jalvarad("jalvarad", 150);
		std::cout << jalvarad << std::endl;
		PresidentialPardonForm form3("Anonimous person");
		std::cout << form3 << std::endl << std::endl;

		adpachec.executeForm(form3);
		std::cout << std::endl;
		adpachec.signForm(form3);
		std::cout << std::endl;
		adpachec.executeForm(form3);
		std::cout << std::endl;
		jalvarad.executeForm(form3);
		std::cout << std::endl;
	}
	catch( std::exception & e)
	{
		std::cout << e.what();
	}
	
	return 0;
}
