/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 13:04:16 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat john("John", 150);
		Bureaucrat alice("Alice", 44);
		Bureaucrat zaphod("Zaphod", 1);
		Bureaucrat henry("Henry", 50);

		ShrubberyCreationForm shrubberyForm("Home");
		RobotomyRequestForm robotomyForm("Robot");
		PresidentialPardonForm pardonForm("Criminal");
		RobotomyRequestForm funkyForm("Funky");

		std::cout << "\nTest signing:" << "\n";
		john.signForm(shrubberyForm);  // Fail
		alice.signForm(robotomyForm);  // Should work
		henry.signForm(funkyForm);	   // Should work
		zaphod.signForm(pardonForm);   // Should work too
		

		std::cout << "\nTest executing:" << "\n";
		john.executeForm(shrubberyForm);  // Fail
		alice.executeForm(robotomyForm);  // Should work
		henry.executeForm(funkyForm);	  // Should fail
		zaphod.executeForm(pardonForm);   // Should work

		std::cout << "\nTest executing unsigned form:" << "\n";
		Bureaucrat bob("Bob", 25);
		bob.executeForm(shrubberyForm);  // Not signed

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return (0);
}
