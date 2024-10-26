/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/25 17:22:45 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	{
		try {
			Bureaucrat Bureaucrat("Mister Too Low", 151);
		} catch (std::exception & e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat Bureaucrat("Mister Too High", 0);
		} catch (std::exception & e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 150);

		try {
			Bureaucrat.decrementGrade();
		} catch (std::exception & e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 1);

		try {
			Bureaucrat.incrementGrade();
		} catch (std::exception &e) {
			std::cout << "Passing through exception\n" << e.what () << std::endl;
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
}