/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 11:16:02 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Adpachec("Adpachec", 1);
		Form form("Form 1", 90, 80);
		std::cout << form << std::endl;

		Adpachec.signForm(form);
		std::cout << form << std::endl << std::endl;

		Adpachec.signForm(form);
		std::cout << form << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Buro("Buro", 100);
		Form form2("Form 2", 90, 80);
		std::cout << form2 << std::endl;

		Buro.signForm(form2);
		std::cout << form2 << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
