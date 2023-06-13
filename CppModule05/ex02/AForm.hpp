/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:34:59 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 13:07:33 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
  class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
	public:
		AForm(void);
		AForm(const std::string& name, const int signGrade, const int executeGrade);
		AForm(const AForm& other);
		~AForm(void);

		AForm& operator=(const AForm& other);

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void checkExecute(Bureaucrat const & executer) const;
		virtual void execute(const Bureaucrat& executor) const = 0;
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif