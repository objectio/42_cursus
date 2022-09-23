/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:10:11 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 13:10:17 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _age(25), _nbChild(0)
{
	return ;
}

Data::Data(unsigned int age, unsigned int nbChild) : _age(age), _nbChild(nbChild)
{
	std::cout << "Constructor called" << std::endl;
}

Data::Data(const Data &data)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}

Data::~Data(void)
{
	std::cout << "Destructor called" << std::endl;
}

Data	&Data::operator=(const Data &data)
{
	if (this == &data)
		return (*this);
	this->_age = data.getAge();
	this->_nbChild = data.getNbChild();
	return (*this);
}

unsigned int	Data::getAge(void)const
{
	return (this->_age);
}

unsigned int	Data::getNbChild(void)const
{
	return (this->_nbChild);
}