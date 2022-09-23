/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:29:00 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:32:25 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form();
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &src);
	virtual ~Form();

	Form &operator=(Form const &rhs);

	bool isSigned() const;
	void beSigned(const Bureaucrat &b);
	const std::string &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void canExecute(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	std::string const _name;
	int _gradeToSign;
	int _gradeToExecute;
	bool _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif