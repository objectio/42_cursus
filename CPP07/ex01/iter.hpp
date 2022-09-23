/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:36:20 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 16:42:09 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>

template <typename T>
void increase(T & n)
{
	n++;
}

template <typename T>
void print_array(T array[], size_t size)
{
	std::cout << "[ ";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i];
		if (i != size - 1)
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

template<typename T>
void print(T const & x) { 
	std::cout << x << " "; return; 
}

template< typename T>
void 	iter(T * array, unsigned int len, void (*pf)(T &))
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		pf(array[i]);
		i++;
	}	
}

template< typename T >
void 	iter(const T * array, unsigned int len, void (*pf)(const T &))
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		pf(array[i]);
		i++;
	}	
}

#endif