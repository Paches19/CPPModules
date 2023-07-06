/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:33:37 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/06 17:49:10 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{}

RPN::RPN(const std::stack<std::string>& stack) : _stack(stack) {}

RPN::RPN(int argc, char *argv[])
{  
	if (!argv || !argv[0])
		return ;
	for (; argc >= 1; --argc)
	{
		std::string word(argv[argc - 1]);
		this->_stack.push(word);
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << this->_stack.top() << std::endl;
		this->_stack.pop();
	}
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN::~RPN() {};

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->setStack(other._stack);
	return *this;
}

void RPN::setStack(std::stack<std::string> stack)
{
	this->_stack = stack;
}

void RPN::calculate()
{
	float num1;
	float num2;                                                   
	float result = 0;

	while (!this->_stack.empty())
	{
		int count = 0;
		while (count < 3)
		{
			num1 = std::atof(this->_stack.top().c_str());
			std::cout << "num1: " << num1 << std::endl;
			this->_stack.pop();
			num2 = std::atof(this->_stack.top().c_str());
			std::cout << "num2: " << num2 << std::endl;
			this->_stack.pop();
			getResult(num1, num2, result);
		}
	}
	std::cout << "result" << result << std::endl;
}

void RPN::getResult(const float & num1, const float & num2, float & result)
{
	std::string operation(this->_stack.top());
	this->_stack.pop();
	
	if (operation == "+")
		result = num1 + num2;
	else if (operation == "-")
		result = num1 - num2;
	else if (operation == "*")
		result = num1 * num2;
	else if (operation == "/")
		result = num1 / num2;
	else
		return ;
}