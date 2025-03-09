/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:02:08 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 13:02:52 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << "\n";
}

Intern::Intern(const Intern &copy) {
	std::cout << "Intern copy constructor called" << "\n";
	*this = copy;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << "\n";
}

Intern& Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return (*this);
}

static AForm* newShrubberyForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm* newRobotomyForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm* newPresidentialForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) {
	if (name.empty()) {
		std::cerr << "The name of the form cannot be empty !" << "\n";
		throw InternFormException();
	} else if (target.empty())
		target = "Dummy target";
	
	std::string form_names[3] = {"ROBOTOMY_REQUEST_FORM", "PRESIDENTIAL_PARDON_FORM", "SHRUBBERY_CREATION_FORM"};
	FormConstructor form_constructor_array[3] = {&newRobotomyForm, &newPresidentialForm, &newShrubberyForm};
	for (unsigned int i = 0; i < 3; i++) {
		if (name == form_names[i]) {
			std::cout << "Match found ! Intern generates form " << name << " for target " << target << "\n";
			return (form_constructor_array[i])(target);
		}
	}
	std::cerr << "No match found :/" << "\n";
	throw InternFormException();
}

const char* Intern::InternFormException::what() const throw () {
	return ("Intern Form exception");
}