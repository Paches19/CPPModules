/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:51:00 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/13 15:41:52 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		
		std::string const & getTarget(void) const;

		virtual void execute(const Bureaucrat& executor) const;
};


#endif