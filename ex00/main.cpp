/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:38 by nechaara          #+#    #+#             */
/*   Updated: 2024/10/25 16:32:53 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	{
		Bureaucrat Bureaucrat("Henry", 150);

		try {
			Bureaucrat.incrementGrade();
		} catch (const std::exception &e) {
			std::cout << "Passing through exception\n" << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Bureaucrat("Henry", 1);

		try {
			Bureaucrat.decrementGrade();
		} catch (const std::exception &e) {
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
}