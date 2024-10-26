/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:26:02 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/25 17:43:43 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
        bool signature;
		const unsigned int _signature_grade;
        const unsigned int _execution_grade;
	public:
		Form(const std::string name, const unsigned int signature_grade, const unsigned int execution_grade);
		Form(const Form &copy);
		~Form();
		Form& operator=(const Form& rhs);
        class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(unsigned int grade) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(unsigned int grade) const throw();
		};
        std::string getName(void) const;
        bool getSignature(void) const;
        unsigned int getSignatureGrade(void) const;
        unsigned int getExecutionGrade(void) const;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif