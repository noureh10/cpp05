/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 14:29:47 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Intern intern;

		AForm* form1 = intern.makeForm("ROBOTOMY_REQUEST_FORM", "Alice");
		AForm* form2 = intern.makeForm("PRESIDENTIAL_PARDON_FORM", "Bob");
		AForm* form3 = intern.makeForm("SHRUBBERY_CREATION_FORM", "Charlie");

		delete form1;
		delete form2;
		delete form3;

		AForm* form4 = intern.makeForm("UNKNOWN_FORM", "Dave");

		delete form4;

	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
