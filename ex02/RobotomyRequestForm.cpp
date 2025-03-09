/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:08:37 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 14:54:35 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm ("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Robotomy Pardon Form constructor called" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy), _target(copy._target) {
	std::cout << "Robotomy Request Form copy constructor called" << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Request Form destructor called" << "\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs)
		this->signature = rhs.getSignature();
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
	executionValidity(bureaucrat);
	std::srand(std::time(0));
	bool choice = std::rand() % 2;

	std::cout << " *LOUD DRILLING NOISE * " << "\n";
	if (choice)
		std::cout << _target << " has been robotomized sucessfully !" << "\n";
	else
		std::cout << _target << " is not POSTing, rip" << "\n";
}