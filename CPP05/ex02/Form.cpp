/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:22:32 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:14:41 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("Default"), gradeToSign(150), gradeToExecute(150), _signed(false)
{
}

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

char const *Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		std::cout << this->getName() << " getting signed by "
				  << b.getName() << std::endl;
		this->_signed = true;
	}
}

void Form::canExecute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->gradeToExecute)
		throw Form::GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->name << std::endl;
}

const std::string &Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool Form::isSigned() const
{
	return (this->_signed);
}