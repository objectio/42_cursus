/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:44 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 12:33:29 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void)
{
	std::cout << "Constructor called" << _target << std::endl;
}

Conversion::Conversion(const std::string av)  : _target(av)
{
	std::cout << "Constructor called for " << _target << std::endl;

	this->_type = this->checkVar();
	this->_double = atof(this->_target.c_str());
	this->convert();
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

Conversion::Conversion(const Conversion &rhs)
{
	std::cout << "Conversion Copy Constructor called" << std::endl;
	*this = rhs;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

Conversion::~Conversion(void)
{
	std::cout << "Destructor called." << std::endl;
}

size_t	countOccurence(char c, const std::string &str)
{
	size_t	count = 0;
	size_t	len = str.size();

	for (size_t i = 0; i < len; i++)
		if (str[i] == c)
			count++;
	return count;
}


std::string	Conversion::checkVar(void)const 
{
	if (this->_target.empty())
		throw Conversion::StringEmpty();
	if (this->_target.size() == 1 && (47 < this->_target[0] && this->_target[0] < 58))
		return ("int");
	else if (this->_target.size() == 1 && (32 < this->_target[0] && this->_target[0] < 127))
		return ("char");
	else if (this->_target == "-inff" || this->_target == "+inff" || this->_target == "nanf" || this->_target == "-inf" || this->_target == "+inf" || this->_target == "nan")
		return ("special");
	else if (((countOccurence('-', this->_target) == 1) && (countOccurence('+', this->_target) == 0) && this->_target[0] == '-')
			|| ((countOccurence('-', this->_target) == 0) && (countOccurence('+', this->_target) == 1) && this->_target[0] == '+')
			|| ((countOccurence('-', this->_target) == 0) && (countOccurence('+', this->_target) == 0)))
	{
		if (this->_target.find_first_not_of("-+0123456789") == std::string::npos)
			return ("int");
		else if ((countOccurence('.', this->_target) == 1) && (countOccurence('f', this->_target) == 1) && (this->_target.find_first_not_of("0123456789.f") == std::string::npos) && (this->_target[this->_target.size() - 1] == 'f') && (this->_target[0] != '.'))
			return ("float");
		else if ((countOccurence('.', this->_target) == 1) && (this->_target.find_first_not_of("0123456789.") == std::string::npos) && (this->_target[0] != '.'))
			return ("double");
	}
	throw Conversion::BadType();
	return ("");
}

void Conversion::fromChar(void)
{
	this->_char = static_cast<unsigned char>(this->_target[0]);
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void Conversion::fromInt(void)
{
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<unsigned char>(this->_int);
	this->_float = static_cast<float>(this->_double);
}

void Conversion::fromDouble(void)
{
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_double);
}

void Conversion::fromFloat(void)
{
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);
}

void	Conversion::convert(void)
{
	void (Conversion::*ptr[])(void) = {&Conversion::fromChar, &Conversion::fromInt, &Conversion::fromChar, &Conversion::fromDouble};
	std::string	type[] = {"char", "int", "float", "double"};

	if (this->_type == "special")
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_type == type[i])
			(this->*ptr[i])();
	}
}

void	Conversion::printChar(void) const
{
	if (this->_double <= 127 && this->_type != "special" && this->_double >= 0)
	{
		if (isprint(this->_char))
			std::cout << "char   : " << this->_char << std::endl;
		else
			std::cout << "char   : Non displayable." << std::endl;
	}
	else
		std::cout << "char   : Impossible." << std::endl;
}


void	Conversion::printInt(void) const
{

	if (this->_type != "special" && this->_double >= std::numeric_limits<int>::min() && this->_double <= std::numeric_limits<int>::max())
		std::cout << "int    : " << this->_int << std::endl;
	else
		std::cout << "int    : Impossible." << std::endl;
}


void	Conversion::printFloat(void) const
{
	if (this->_type != "special")
	{
		std::cout << "float  : " << this->_float;
		if (this->_float - this->_int == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->_target == "nan" || this->_target == "nanf")
			std::cout << "float  : nanf" << std::endl;
		else if (this->_target[0] == '+')
			std::cout << "float   : +inff" << std::endl;
		else
			std::cout << "float   : -inff" << std::endl;
	}
}
	
void	Conversion::printDouble(void) const
{
	if (this->_type != "special")
	{
		std::cout << "double : " << this->_double;
		if (this->_double - this->_int == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
	{
		if (this->_target == "nan" || this->_target == "nanf")
			std::cout << "double : nan" << std::endl;
		else if (this->_target[0] == '+')
			std::cout << "double : +inf" << std::endl;
		else
			std::cout << "double : -inf" << std::endl;
	}
}

char	Conversion::getChar(void)const
{
	return (this->_char);
}

int	Conversion::getInt(void)const
{
	return (this->_int);
}


double	Conversion::getDouble(void)const
{
	return (this->_double);
}

float	Conversion::getFloat(void)const
{
	return (this->_float);
}

std::string	Conversion::getType(void)const
{
	return (this->_type);
}

Conversion &Conversion::operator=(const Conversion &rhs)
{
	std::cout << "Conversion Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	this->_char = rhs.getChar();
	this->_int = rhs.getInt();
	this->_float = rhs.getFloat();
	this->_double = rhs.getDouble();
	return (*this);
}