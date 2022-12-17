/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:51 by younjkim          #+#    #+#             */
/*   Updated: 2022/12/17 17:55:52 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/containers.hpp"

#include <iostream>
#include <cctype>

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	char foo[]="Apple";
  	char bar[]="apartment";

	std::cout << std::boolalpha;
 	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
 	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
 	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';

	return (0);
}