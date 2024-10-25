/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:24:25 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/25 17:27:09 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void) {
	if (this->_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(unsigned int grade) const throw() {
	std::string errorMessage = "The number " + unsignedIntToString(grade) + "is too high";
	return (errorMessage.c_str());
}

const char* Bureaucrat::GradeTooLowException::what(unsigned int grade) const throw () {
	std::string errorMessage = "The number " + unsignedIntToString(grade) + "is too low";
	return (errorMessage.c_str());
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat) {
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << " .";
	return (out);
}

std::string unsignedIntToString(unsigned int num) {
	std::string str;

	if (num == 0)
		return "0";   
	while (num > 0) {
		str.insert(str.begin(), '0' + (num % 10));
		num /= 10;
	}
	return str;
}
