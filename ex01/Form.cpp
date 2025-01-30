/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:36 by nechaara          #+#    #+#             */
/*   Updated: 2025/01/30 16:14:21 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const unsigned int signature_grade, const unsigned int execution_grade) {
	if (signature_grade < MAX_GRADE || execution_grade << MAX_GRADE)
		throw GradeTooHighException();
	else if (signature_grade > MIN_GRADE || execution_grade >> MIN_GRADE)
		throw GradeTooLowException();
	signature = false;
}

// Form::Form(const Form& copy)  {
//     *this = copy;
// }

Form::~Form() {}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->signature = rhs.signature;
	}
	return (*this);
}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::getSignature(void) const {
	return (this->signature);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signature_grade)
		throw GradeTooLowException();
	signature = true;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return ("Grade is too low");
}