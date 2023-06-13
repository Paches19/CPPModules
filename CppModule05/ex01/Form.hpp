/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:34:59 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 11:10:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
  class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
	public:
		Form(void);
		Form(const std::string& name, const int signGrade, const int executeGrade);
		Form(const Form& other);
		~Form(void);

		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class SignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif