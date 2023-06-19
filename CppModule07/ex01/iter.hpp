/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:16:20 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/19 11:21:14 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename F>
void iter(T* array, int len, F function)
{
	for (int i = 0; i < len; ++i)
		function(array[i]);
}

#endif
