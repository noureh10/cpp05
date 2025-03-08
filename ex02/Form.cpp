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

Form::Form(const std::string name, unsigned int signature_grade, unsigned int execution_grade) 
    : _name(name), signature(false), _signature_grade(signature_grade), _execution_grade(execution_grade) {
    std::cout << "Form constructor called" << "\n";
	if (signature_grade < MAX_GRADE || execution_grade < MAX_GRADE) 
        throw Form::GradeTooHighException();
    else if (signature_grade > MIN_GRADE || execution_grade > MIN_GRADE) 
        throw Form::GradeTooLowException();
}


Form::Form(const Form& copy) : _name(copy._name), signature(copy.signature), _signature_grade(copy._signature_grade), _execution_grade(copy._execution_grade){
    std::cout << copy._name << " copy constructor form called" << "\n";
}

Form::~Form() {
	std::cout << this->_name << " destructor called" << "\n";
}

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

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form - Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw () {
	return ("Form - Grade is too low");
}

unsigned int Form::getSignatureGrade(void) const {
	return (this->_signature_grade);
}

unsigned int Form::getExecutionGrade(void) const {
	return (this->_execution_grade);
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form Name: " << form.getName() 
		<< ", Signed: " << (form.getSignature() ? "Yes" : "No")
		<< ", Required Sign Grade: " << form.getSignatureGrade()
		<< ", Required Execution Grade: " << form.getExecutionGrade();
	return out;
}
