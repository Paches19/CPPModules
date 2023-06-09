/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:23:22 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/30 13:26:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << this->_fractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->setRawBits(other.getRawBits());
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float) (this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_fractionalBits;
}
