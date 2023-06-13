/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:17:06 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 13:35:24 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;
		RobotomyRequestForm & operator=(RobotomyRequestForm &src);
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string const & getTarget(void) const;

		virtual void execute(const Bureaucrat& executor) const;
};

#endif