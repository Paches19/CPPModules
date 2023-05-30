/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:23:07 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/30 17:09:21 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;

	Fixed d(33.75f);
	Fixed c(2);
	std::cout << "d/c: " << d/c << std::endl;
	std::cout << "d*c: " << d*c << std::endl;
	std::cout << "d+c: " << d+c << std::endl;
	std::cout << "d-c: " << d-c << std::endl;
	
	if (a != c)
		std::cout << "a != c " << std::endl;
	if (!(a == c))
		std::cout << "!(a == c) " << std::endl;
	
	return 0;
}
