/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:33:37 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/22 10:36:44 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

template <typename T>
void printStack(const std::stack<T>& s)
{
    std::stack<T> tempStack = s;

    while (!tempStack.empty())
    {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    std::cout << std::endl;
}

RPN::RPN(char *argv[])
{
	std::vector<std::string> tempVec;
	std::string token;
	std::string arg = argv[1];
	size_t pos = 0;

	while((pos = arg.find(' ')) != std::string::npos)
	{
		token = arg.substr(0, pos);
		tempVec.push_back(token);
		arg.erase(0, pos + 1);
	}
	tempVec.push_back(arg);

	for(std::vector<std::string>::reverse_iterator it = tempVec.rbegin();
		it != tempVec.rend(); ++it)
		_stack.push(*it);
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN::~RPN() {};

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

void RPN::setStack(std::stack<std::string> stack)
{
	this->_stack = stack;
}

void RPN::calculate()
{
	std::stack<float> resultStack;

	while (!this->_stack.empty())
	{
		const std::string token = this->_stack.top();
		this->_stack.pop();
		if (isNumber(token))
		{
			float number = std::atof(token.c_str());
			resultStack.push(number);
		}
		else if (isOperand(token))
		{
			if (resultStack.size() < 2)
			{
				std::cerr << "Error: Insufficient operands for operation." << std::endl;
				return ;
			}
			float operand2 = resultStack.top();
			resultStack.pop();
			float operand1 = resultStack.top();
			resultStack.pop();
			float result = 0.0;
			getResult(token, operand1, operand2, result);
			resultStack.push(result);
		}
		else
		{
			std::cerr << "Error: Invalid token." << std::endl;
			return;
		}
	}

	if (resultStack.size() != 1)
	{
		std::cerr << "Error: Invalid expression. Cannot get a result" << std::endl;
		return;
	}

	std::cout << resultStack.top() << std::endl;
	resultStack.pop();
}

void RPN::getResult(const std::string& operation, float& operand1, float& operand2, float& result) const
{
	if (operation == "+")
		result = operand1 + operand2;
	else if (operation == "-")
		result = operand1 - operand2;
	else if (operation == "*")
		result = operand1 * operand2;
	else if (operation == "/" && operand2 != 0)
		result = operand1 / operand2;
	else
		result = 0.0;
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;

	for (std::size_t i = 0; i < token.length(); ++i)
	{
		if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}

bool RPN::isOperand(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}