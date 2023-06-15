/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/15 14:03:35 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate()
{
	srand(time(0));
	int ran = rand() % 3;

	switch (ran)
	{
		case 0:
			std::cout << "A class created!" << std::endl ;
			return new A();
		case 1:
			std::cout << "B class created!" << std::endl ;
			return new B();
		case 2:
			std::cout << "C class created!" << std::endl ;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

int main()
{
	Base *p = generate();
	identify(p);

	delete p;
	return 0;
}
