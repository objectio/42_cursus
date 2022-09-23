/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:23:41 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:36:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern &operator=(Intern const &rhs);

	Form *makeForm(std::string const &form, std::string const &target) const;

	class InternException
		: public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	Form *makePresidentalPardonForm(std::string const &) const;
	Form *makeRobotomyRequestForm(std::string const &) const;
	Form *makeShrubberyCreationForm(std::string const &) const;
	Form *makeErrorForm(std::string const &) const;
};

std::ostream &operator<<(std::ostream &o, Intern const &i);

#endif