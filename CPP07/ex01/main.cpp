/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:35:34 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 16:46:01 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void divide_int(int & n)
{
	n /= 10;
}

void divide_double(double & d)
{
	d /= 10;
}

template void increase(int &);

void str_toupper(std::string & str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int main(void)
{
	// Int tests
	{
		int a[5] = { 10, 50, 30, 40, 20 };

		std::cout << "Array before calling template :" << std::endl;
		::iter(a, 5, print);
		std::cout << std::endl;
		iter<int>(a, 5, &divide_int);
		std::cout << "Array after calling template :" << std::endl;
		::print_array(a, 5);
	}
	std::cout << std::endl;
	{
		double a[5] = { 25.5, 31.0, 12, 14, 17 };

		std::cout << "Array before calling template :" << std::endl;
		::print_array(a, 5);
		iter<double>(a, 5, &divide_double);
		std::cout << "Array after calling template :" << std::endl;
		::iter(a, 5, print);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		int a[5] = { 10, 50, 30, 40, 20 };

		std::cout << "Array before calling template :" << std::endl;
		::print_array(a, 5);
		iter<int>(a, 5, &increase);
		std::cout << "Array after calling template :" << std::endl;
		::print_array(a, 5);
	}
	std::cout << std::endl;
	// String tests
	{
		std::string str[2] = { "first" , "second" };

		std::cout << "Array before calling template :" << std::endl;
		::iter(str, 2, print);
		std::cout << std::endl;
		iter<std::string>(str, 2, &str_toupper);
		std::cout << "Array after calling template :" << std::endl;
		::iter(str, 2, print);
		std::cout << std::endl;
	}

	return (0);	
}