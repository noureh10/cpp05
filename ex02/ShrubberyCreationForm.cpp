/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:18:09 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/08 17:15:23 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm ("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Shrubbery Creation Form constructor called" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy), _target(copy._target) {
	std::cout << "Shrubbery Creation Form copy constructor called" << "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation Form destructor called" << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs)
		this->signature = rhs.getSignature();
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
	executionValidity(bureaucrat);
	std::ofstream output_file((this->_target + "_shrubbery").c_str());
	int height = 5;
	if (output_file.is_open()) {
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= height - i; j++)
				output_file << " ";
			for (int j = 1; j <= (2 * i - 1); j++)
				output_file << "*";
			output_file << "\n";
		}
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j < height; j++)
				output_file << " ";
			output_file << "*" << "\n";
		}
	} else
		std::cerr << "File couldn't be opened" << "\n";
}