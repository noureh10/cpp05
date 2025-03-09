/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:02:05 by nechaara          #+#    #+#             */
/*   Updated: 2025/03/09 13:24:05 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &rhs);
		AForm* makeForm(std::string name, std::string target);
		class InternFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		typedef AForm* (*FormConstructor)(const std::string);
};


#endif