/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:14:44 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:07:01 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("Default"), gradeToSign(150), gradeToExecute(150), _signed(false)
{}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
{
	*this = src;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->gradeToExecute = rhs.getGradeToExecute();
		this->gradeToSign = rhs.getGradeToSign();
		this->_signed = rhs.isSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form name: " << i.getName() << std::endl;
	o << "Grade to sign: " << i.getGradeToSign() << std::endl;
	o << "Grade to execute: " << i.getGradeToExecute() << std::endl;
	o << "Form signed: " << i.isSigned() << std::endl;
	return o;
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
		this->_signed = true;
	}
}

const std::string &Form::getName(void) const
{
	return (this->name);
}

int Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}