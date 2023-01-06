/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:51 by younjkim          #+#    #+#             */
/*   Updated: 2023/01/06 13:18:49 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/containers.hpp"

#include <iostream>
#include <cctype>

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
is_odd (T i) { return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
is_even (T i) { return !bool(i%2);}

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	{
		// ft::vector v(1, 5);
		// std::cout << v.begin() << std::endl;
	}

	{
		char foo[]="Apple";
		char bar[]="apartment";

		std::cout << std::boolalpha;
		std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
		std::cout << '\n';

		std::cout << "Using mycomp as comparison object: ";
		std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
		std::cout << '\n';
	}

	std::cout << std::endl;

	{
		short int i = 1;    // code does not compile if type of i is not integral

		std::cout << std::boolalpha;
		std::cout << "i is odd: " << is_odd(i) << std::endl;
		std::cout << "i is even: " << is_even(i) << std::endl;
	}

	return (0);
}