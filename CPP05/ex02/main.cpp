/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:30:35 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 12:30:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main(void)
{
	srand(time(NULL));
	{
		std::cout << "-----------Presidential Pardon----------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		PresidentialPardonForm form001("Angela Davis");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		jan.executeForm(form001);
		max.signForm(form001);
		jan.signForm(form001);
		max.executeForm(form001);
		jan.executeForm(form001);
	}

	{
		std::cout << "-----------Robotomy Request-------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		RobotomyRequestForm form002("Compiler");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		max.executeForm(form002);
		jan.signForm(form002);
		max.signForm(form002);
		jan.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
	}

	{
		std::cout << "-----------Shrubbery Creation-----------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		ShrubberyCreationForm form003("Backyard");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		max.executeForm(form003);
		jan.signForm(form003);
		max.signForm(form003);
		jan.executeForm(form003);
		max.executeForm(form003);
	}
}