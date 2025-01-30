/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:24:25 by nechaara          #+#    #+#             */
/*   Updated: 2025/01/30 16:14:02 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	*this = copy;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high, aborting");
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return ("Grade is too low, aborting");
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

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}
