/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:14 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:23:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "string"

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(void);
		Weapon(const std::string& type);
		~Weapon(void);
		const std::string& getType() const;
		void setType(const std::string& type);
};

#endif
