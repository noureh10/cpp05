/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:26:02 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 13:09:12 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string _name;
		bool signature;
		const unsigned int _signature_grade;
		const unsigned int _execution_grade;
	public:
		AForm();
		AForm(const std::string name, unsigned int signature_grade, unsigned int execution_grade);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm& operator=(const AForm& rhs);
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		std::string getName(void) const;
		bool getSignature(void) const;
		void executionValidity(const Bureaucrat &bureaucrat) const;
		unsigned int getSignatureGrade(void) const;
		unsigned int getExecutionGrade(void) const;
		void beSigned(const Bureaucrat& bureaucrat);
		bool isSigned(void) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif