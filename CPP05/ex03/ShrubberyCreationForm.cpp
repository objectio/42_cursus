/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 07:40:05 by younjkim         #+#    #+#             */
/*   Updated: 2022/08/22 19:38:14 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << "Target = " << i.getTarget();
	return o;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::ofstream file;
	file.open(("./" + this->_target + "_shrubbery").c_str());
	for (int i = 0; i < 10; i++)
	{
		file << "              ,@@@@@@@,               " << std::endl;
		file << "      ,,,.   ,@@@@@@/@@,  .oo8888o.   " << std::endl;
		file << "   ,&%%&%&&%,@@@@@/@@@@@@,888888/8o  " << std::endl;
		file << "  ,%&%&&%&&%,@@@@@@/@@@8888888/88$$$' " << std::endl;
		file << "  %&&%&%&/%&&%@@@@/ /@@@8888888888$$' " << std::endl;
		file << "  %&&%/ %&%%&&@@ V /@@' `88\\8 `/88'  " << std::endl;
		file << "  `&% ` /%&'    |.|        \\ '|8'    " << std::endl;
		file << "     |o|        | |         | |       " << std::endl;
		file << "     |.|        | |         | |       " << std::endl;
		file << "    / ._\\//_/_/  ,\\_//___/.  \\_//__/" << std::endl;
		file << std::endl;
	}
	file.close();
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}