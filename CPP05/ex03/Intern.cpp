/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:23:49 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:44:36 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentalPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	(void)i;
	return o;
}

Form *Intern::makeForm(std::string const &form, std::string const &target) const
{
	Form *new_form;
	int i = 0;
	Form *(Intern::*forms[4])(std::string const &) const = {&Intern::makePresidentalPardonForm,
															&Intern::makeRobotomyRequestForm,
															&Intern::makeShrubberyCreationForm,
															&Intern::makeErrorForm};
	std::string request[3] = {
		"ppf",
		"rrf",
		"scf"};
	while (request[i].compare(form) && i < 3)
		i++;
	new_form = (this->*forms[i])(target);
	std::cout << "Intern creates " << new_form->getName() << std::endl;
	return (new_form);
}

Form *Intern::makePresidentalPardonForm(std::string const &target) const
{
	Form *new_form = new PresidentalPardonForm(target);
	return (new_form);
}

Form *Intern::makeRobotomyRequestForm(std::string const &target) const
{
	Form *new_form = new RobotomyRequestForm(target);
	return (new_form);
}

Form *Intern::makeShrubberyCreationForm(std::string const &target) const
{
	Form *new_form = new ShrubberyCreationForm(target);
	return (new_form);
}

const char *Intern::InternException::what() const throw()
{
	return "Unknown form!";
}

Form *Intern::makeErrorForm(std::string const &) const
{
	Form *new_form = NULL;
	throw Intern::InternException();
	return (new_form);
}
