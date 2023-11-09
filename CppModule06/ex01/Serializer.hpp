/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:55:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/09 16:11:14 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Serializer
{
	private:
		int	_num;

		Serializer();
		Serializer(int num);

	public:
		~Serializer();
		Serializer(const Serializer& other);

		Serializer& operator=(const Serializer& other);
		
		uintptr_t serialize(Serializer* ptr);
		Serializer* deserialize(uintptr_t raw);
		
		static Serializer* crearSerializer(int num);
		int getNum(void) const;
};

#endif
