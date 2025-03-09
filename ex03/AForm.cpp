/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:36 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/08 16:55:35 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default form"), _signature_grade(MIN_GRADE), _execution_grade(MIN_GRADE) {
	std::cout << "Default constructor called" << "\n";
}

AForm::AForm(const std::string name, unsigned int signature_grade, unsigned int execution_grade) 
    : _name(name), signature(false), _signature_grade(signature_grade), _execution_grade(execution_grade) {
    std::cout << "Form constructor called" << "\n";
	if (signature_grade < MAX_GRADE || execution_grade < MAX_GRADE) 
        throw AForm::GradeTooHighException();
    else if (signature_grade > MIN_GRADE || execution_grade > MIN_GRADE) 
        throw AForm::GradeTooLowException();
}


AForm::AForm(const AForm& copy) : _name(copy._name), signature(copy.signature), _signature_grade(copy._signature_grade), _execution_grade(copy._execution_grade) {
    std::cout << copy._name << " copy constructor form called" << "\n";
}

AForm::~AForm() {
	std::cout << this->_name << " destructor called" << "\n";
}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->signature = rhs.signature;
	}
	return (*this);
}

std::string AForm::getName(void) const {
	return (this->_name);
}

bool AForm::getSignature(void) const {
	return (this->signature);
}

void AForm::executionValidity(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() > _execution_grade)
		throw GradeTooLowException();
	if (!this->signature)
		throw FormNotSignedException();
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signature_grade)
		throw GradeTooLowException();
	signature = true;
}

bool AForm::isSigned(void) const {
	return (signature);
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form - The form needs to be signed");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Form - Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw () {
	return ("Form - Grade is too low");
}

unsigned int AForm::getSignatureGrade(void) const {
	return (this->_signature_grade);
}

unsigned int AForm::getExecutionGrade(void) const {
	return (this->_execution_grade);
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Form Name: " << form.getName() 
		<< ", Signed: " << (form.getSignature() ? "Yes" : "No")
		<< ", Required Sign Grade: " << form.getSignatureGrade()
		<< ", Required Execution Grade: " << form.getExecutionGrade();
	return out;
}
