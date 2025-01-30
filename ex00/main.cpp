/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2024/12/15 20:20:14 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	{
		try {
			Bureaucrat Bureaucrat("Mister Too Low", 151);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat Bureaucrat("Mister Too High", 0);
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 150);

		try {
			Bureaucrat.decrementGrade();
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 1);

		try {
			Bureaucrat.incrementGrade();
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 25);
		std::cout << Bureaucrat << std::endl;
	}
	{
		Bureaucrat idiot1("Jean", 144);
		Bureaucrat idiot2("Mary", 25);
		idiot1 = idiot2;
		std::cout << idiot1 << std::endl;
		
	}
	{
		int grade;
		grade = 15000;
		try {
			Bureaucrat Bureaucrat("Henry", grade);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
		grade = -2000;
		try {
			Bureaucrat Bureaucrat("Henry", -2000);
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
}