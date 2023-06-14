/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:01:58 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 13:13:31 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137),
_target("NO TARGET")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

const char* ShrubberyCreationForm::ErrorFile::what() const throw()
{
	return "Failed to open file for writing!";
}

std::string const & ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	this->checkExecute(executor);

	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << "              ,@@@@@@@,\n"
        "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
        "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        "  `&%\\ ` /%&'    |.|        \\ '|8'\n"
        "      |o|        | |         | |\n"
        "      |.|        | |         | |\n"
        "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
		<< std::endl;
		file.close();
	}
	else
	{
		throw ErrorFile();
	}
}
