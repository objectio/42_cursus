/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:00:22 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:53:43 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main()
{
	Form *form = NULL;
	Intern intern;

	srand(time(NULL));

	try
	{
		form = intern.makeForm("rrf", "Compiler");
		std::cout << *form << std::endl;
		Bureaucrat max("Max Senges", 20);
		std::cout << max << std::endl;
		max.signForm(*form);
		max.executeForm(*form);
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		;
	}

	if (form)
		delete form;
	form = NULL;
	std::cout << "-----------------" << std::endl;

	try
	{
		form = intern.makeForm("ppf", "Angela Davis");
		std::cout << *form << std::endl;
		Bureaucrat max("Max Senges", 20);
		std::cout << max << std::endl;
		max.signForm(*form);
		max.executeForm(*form);
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		;
	}

	if (form)
		delete form;
	form = NULL;
	std::cout << "-----------------" << std::endl;

	try
	{
		form = intern.makeForm("scf", "Backyard");
		std::cout << *form << std::endl;
		Bureaucrat max("Max Senges", 20);
		std::cout << max << std::endl;
		max.signForm(*form);
		max.executeForm(*form);
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		;
	}

	if (form)
		delete form;
	form = NULL;
	std::cout << "-----------------" << std::endl;

	return (0);
}