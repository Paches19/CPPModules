/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:23:16 by adpachec          #+#    #+#             */
/*   Updated: 2023/05/30 12:05:17 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed& operator=(const Fixed& other);

		int getRawBits(void) const;
		void setRawBits(int raw);
};

#endif
