/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 07:39:41 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 19:42:46 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentalPardonForm
	: public Form
{

public:
	PresidentalPardonForm();
	PresidentalPardonForm(std::string const _target);
	PresidentalPardonForm(PresidentalPardonForm const &src);
	~PresidentalPardonForm();

	PresidentalPardonForm &operator=(PresidentalPardonForm const &rhs);

	void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentalPardonForm const &i);

#endif