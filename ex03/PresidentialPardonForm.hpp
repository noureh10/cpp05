/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:09:06 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 12:19:36 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm const &rhs);
		void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm& form);

#endif