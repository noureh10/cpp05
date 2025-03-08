/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2025/01/30 16:16:38 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	{
		try {
			Form form("Form 1", 0, 50);
		} catch (Form::GradeTooHighException &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		try {
			Form form("Form 2", 151, 50);
		} catch (Form::GradeTooLowException &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		try {
			Form form("Form 3", 50, 0);
		} catch (Form::GradeTooHighException &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		try {
			Form form("Form 4", 50, 151);
		} catch (Form::GradeTooLowException &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat john("John", 30);
		Form form("Form 5", 40, 50);
		std::cout << form << std::endl;
		try {
			form.beSigned(john);
			std::cout << "John successfully signed the form." << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cout << "John couldn't sign the form: " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat alice("Alice", 50);
		Form form("Form 6", 40, 50);
		std::cout << form << std::endl;
		try {
			form.beSigned(alice);
		} catch (Form::GradeTooLowException &e) {
			std::cout << "Alice couldn't sign the form: " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat bob("Bob", 35);
		Form form("Form 7", 35, 50);
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	return 0;
}
