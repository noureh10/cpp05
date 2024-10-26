/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:36 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/26 18:25:09 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const unsigned int signature_grade, const unsigned int execution_grade) : 
    _name(name), _signature_grade(signature_grade), _execution_grade(execution_grade) {
        
}

Form::Form(const Form& copy) : _name(copy._name), _signature_grade(copy._signature_grade), _execution_grade(copy._execution_grade) {
    
}

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

const char* Bureaucrat::GradeTooHighException::what(unsigned int grade) const throw() {
	std::string errorMessage = "The number " + unsignedIntToString(grade) + "is too high";
	return (errorMessage.c_str());
}

const char* Bureaucrat::GradeTooLowException::what(unsigned int grade) const throw () {
	std::string errorMessage = "The number " + unsignedIntToString(grade) + "is too low";
	return (errorMessage.c_str());
}