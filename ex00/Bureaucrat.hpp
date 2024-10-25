/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:09:31 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/25 16:16:58 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#define MIN_GRADE 1
#define MAX_GRADE 150


class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(unsigned int grade) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(unsigned int grade) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);
std::string unsignedIntToString(unsigned int num);

#endif