/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:48:28 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 16:33:47 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const int v)
{
    this->setRawBits(v << fbit);
}

Fixed::Fixed(const float fv)
{
    this->setRawBits((int)(roundf(fv * (1 << this->fbit))));
}

Fixed::Fixed(const Fixed& fixed)
{
    this->value = fixed.getRawBits();
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    this->value = fixed.value;
    this->setRawBits(fixed.getRawBits());
    return *this;
}

Fixed::~Fixed() 
{
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

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    return f1 < f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return f1 < f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return f1 > f2 ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return f1 > f2 ? f1 : f2;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{   
    return out << fixed.toFloat();
}

bool operator>(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() > f2.getRawBits());
}

bool operator<(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() < f2.getRawBits());
}

bool operator>=(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() >= f2.getRawBits());
}

bool operator<=(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() <= f2.getRawBits());
}

bool operator==(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() == f2.getRawBits());
}

bool operator!=(const Fixed& f1, const Fixed& f2)
{
    return (f1.getRawBits() != f2.getRawBits());
}

Fixed operator+(const Fixed& f1, const Fixed& f2)
{
    Fixed newf;
    newf.setRawBits(f1.getRawBits() + f2.getRawBits());
    return (newf);
}

Fixed operator-(const Fixed& f1, const Fixed& f2)
{
    Fixed newf;
    newf.setRawBits(f1.getRawBits() - f2.getRawBits());
    return (newf);
}

Fixed operator*(const Fixed& f1, const Fixed& f2)
{
    return (f1.toFloat() * f2.toFloat());
}

Fixed operator/(const Fixed& f1, const Fixed& f2)
{
    if (f1.getRawBits() == 0 || f2.getRawBits() == 0)
    {
        std::cout << "It cannot divide." << std::endl;
        return (-1);
    }
    return (f1.toFloat() / f2.toFloat());
}

Fixed& operator++(Fixed& f1)
{
    int nraw;
    nraw = f1.getRawBits();
    nraw++;
    f1.setRawBits(nraw);
    return (f1);
}

Fixed operator++(Fixed& f1, int dummy)
{
    (void) dummy;
    Fixed nf;
    int nraw;

    nraw = f1.getRawBits();
    nf.setRawBits(nraw);
    nraw++;
    f1.setRawBits(nraw);
    return (nf);
}

Fixed& operator--(Fixed& f1)
{
    int nraw;
    nraw = f1.getRawBits();
    nraw--;
    f1.setRawBits(nraw);
    return (f1);
}

Fixed operator--(Fixed& f1, int dummy)
{
    (void) dummy;
    Fixed nf;
    int nraw;

    nraw = f1.getRawBits();
    nf.setRawBits(nraw);
    nraw--;
    f1.setRawBits(nraw);
    return (nf);
}