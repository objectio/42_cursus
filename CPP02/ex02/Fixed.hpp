/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:48:35 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 13:49:29 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
    int value;
    static const int fbit = 8;

    public:
    Fixed();
    Fixed(const int v);
    Fixed(const float fv);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed& min(Fixed& f1, Fixed& f2);
    const static Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    const static Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

bool operator>(const Fixed& f1, const Fixed& f2);
bool operator<(const Fixed& f1, const Fixed& f2);
bool operator>=(const Fixed& f1, const Fixed& f2);
bool operator<=(const Fixed& f1, const Fixed& f2);
bool operator==(const Fixed& f1, const Fixed& f2);
bool operator!=(const Fixed& f1, const Fixed& f2);

Fixed operator+(const Fixed& f1, const Fixed& f2);
Fixed operator-(const Fixed& f1, const Fixed& f2);
Fixed operator*(const Fixed& f1, const Fixed& f2);
Fixed operator/(const Fixed& f1, const Fixed& f2);

Fixed& operator++(Fixed& f1);
Fixed operator++(Fixed& f1, int dummy);
Fixed& operator--(Fixed& f1);
Fixed operator--(Fixed& f1, int dummy);

#endif