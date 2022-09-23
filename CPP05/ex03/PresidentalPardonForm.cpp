/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 07:39:33 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:36:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm()
	: Form("PresidentialPardonForm", 25, 5), _target("Default")
{
}

PresidentalPardonForm::PresidentalPardonForm(std::string const target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm &src)
{
	*this = src;
}

PresidentalPardonForm::~PresidentalPardonForm()
{
}

PresidentalPardonForm &PresidentalPardonForm::operator=(PresidentalPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentalPardonForm const &i)
{
	o << "Target = " << i.getTarget();
	return o;
}

void PresidentalPardonForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const std::string &PresidentalPardonForm::getTarget() const
{
	return (this->_target);
}
