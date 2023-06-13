/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 11:08:45 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Adpachec("Adpachec", 100);
		std::cout << Adpachec << std::endl;

		Adpachec.incrementGrade();
		std::cout << Adpachec << std::endl;

		Adpachec.decrementGrade();
		std::cout << Adpachec << std::endl;

		Bureaucrat tooLow("Too Low", 160);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooHigh("Too High", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat Limit("Limit", 150);

		std::cout << Limit << std::endl;
		Limit.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat LimitUp("LimitUp", 1);
		std::cout << LimitUp << std::endl;
		LimitUp.incrementGrade();
		
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
