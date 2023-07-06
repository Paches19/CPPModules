/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:33:40 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/06 17:48:02 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>

class RPN
{
	private:
		std::stack<std::string>& _stack;

	public:
		RPN(void);
		RPN(const std::stack<std::string>& stack);
		RPN(int argc, char *argv[]);
		RPN(const RPN& other);
		~RPN(void);

		RPN& operator=(const RPN& other);

		void setStack(std::stack<std::string> stack);
		void calculate();
		void getResult(const float & num1, const float & num2, float & result);
};

#endif