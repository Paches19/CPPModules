/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:41:00 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 17:06:06 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):_name("No name"), _signed(false), _signGrade(150), _executeGrade(150){}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other.getName()), _signed(other.isSigned()),
	_signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& other)
{
	this->_signed = other.isSigned();

	return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

const char* AForm::SignedException::what() const throw()
{
	return "Form is already signed!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed already. You need to sign it before execute it!";
}

const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw SignedException();
	else if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecute(Bureaucrat const & executer) const
{
	if(!this->isSigned())
		throw NotSignedException();
	else if (this->getExecuteGrade() < executer.getGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << Aform.getName() << ": Signed: " << (Aform.isSigned() ? "Yes" : "No")
	<< " | Grade Required to Sign: " << Aform.getSignGrade()
	<< " | Grade Required to Execute: " << Aform.getExecuteGrade();
	return os;
}
