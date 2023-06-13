/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:41:00 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 11:15:37 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):_name("No name"), _signed(false), _signGrade(150), _executeGrade(150){}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other.getName()), _signed(other.isSigned()),
	_signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
{
	this->_signed = other.isSigned();

	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

const char* Form::SignedException::what() const throw()
{
	return "form is already signed!";
}

const std::string& Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw SignedException();
	else if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ": Signed: " << (form.isSigned() ? "Yes" : "No")
	<< " | Grade Required to Sign: " << form.getSignGrade()
	<< " | Grade Required to Execute: " << form.getExecuteGrade();
	return os;
}
