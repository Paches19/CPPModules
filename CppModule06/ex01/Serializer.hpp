/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:55:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/09 14:09:46 by adpachec         ###   ########.fr       */
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
		~Serializer();
		Serializer(const Serializer& other);

		Serializer& operator=(const Serializer& other);

	public:
		uintptr_t serialize(Serializer* ptr);
		Serializer* deserialize(uintptr_t raw);
		
		int	getNum(void);
};

#endif
