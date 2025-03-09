/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:19:31 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/08 17:14:49 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm ("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Presidential Pardon Form constructor called" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy), _target(copy._target) {
	std::cout << "Presidential Pardon Form copy constructor called" << "\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon Form destructor called" << "\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs)
		this->signature = rhs.getSignature();
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const{
	executionValidity(bureaucrat);
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << "\n";
}