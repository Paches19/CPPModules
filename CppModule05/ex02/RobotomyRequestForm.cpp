/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:17:06 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 13:36:13 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

std::string const & RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{

	this->checkExecute(executor);

	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	std::cout << "* Drilling noises *" << std::endl;

	std::srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy request on " << this->_target << " failed." << std::endl;
}
