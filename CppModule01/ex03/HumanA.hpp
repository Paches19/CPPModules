/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:13:41 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/26 11:23:51 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include "string"

class HumanA
{
	private:
		std::string _name;
		const Weapon& _weapon;

	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA(void);
		void attack() const;
};

#endif
