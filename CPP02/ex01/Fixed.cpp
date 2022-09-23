/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:55:06 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 16:34:42 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int v)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(v << fbit);
}

Fixed::Fixed(const float fv)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)(roundf(fv * (1 << this->fbit))));
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.value;
    this->setRawBits(fixed.getRawBits());
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->getRawBits()) / static_cast<float>(1 << this->fbit)); 
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->fbit); 
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    return out << fixed.toFloat();
}