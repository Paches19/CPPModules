/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:20:30 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:28:31 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "iostream"
#include "string"

class HumanB
{
	private:
		std::string _name;
		const Weapon* _weapon;
	
	public:
		HumanB(const std::string& name);
		HumanB(void);
		~HumanB(void);
		void setWeapon(const Weapon& weapon);
		void attack() const;
};

#endif
