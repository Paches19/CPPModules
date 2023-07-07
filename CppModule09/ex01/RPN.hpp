/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:33:40 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/07 14:04:39 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <cstring>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <vector>

class RPN
{
	private:
		std::stack<std::string> _stack;

	public:
		RPN(void);
		RPN(char *argv[]);
		RPN(const RPN& other);
		~RPN(void);

		RPN& operator=(const RPN& other);

		void setStack(std::stack<std::string> stack);
		void calculate(void);
		void getResult(const std::string& operation, float& num1,
			float& num2, float& result) const;
		bool isNumber(const std::string& token) const;
		bool isOperand(const std::string& token) const;
};

#endif