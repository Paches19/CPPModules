/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:12 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 16:26:12 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5),
_target("NO TARGET")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

std::string const & PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->checkExecute(executor);

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
}
