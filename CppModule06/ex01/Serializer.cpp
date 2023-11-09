/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:45 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/09 16:11:18 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() : _num(0) {}

Serializer::Serializer(int num) : _num(num) {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) : _num(other.getNum()) {}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
		Serializer(other.getNum());
	return *this;
}

Serializer* Serializer::crearSerializer(int num)
{
	return (new Serializer(num));
}

uintptr_t Serializer::serialize(Serializer* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Serializer* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Serializer*>(raw);
}

int Serializer::getNum(void) const
{
	return (this->_num);
}