/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:45:04 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:45:04 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <deque>
#include <stack>
#include <list>

template <typename T>
void easyfind(T & container, int n)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), n);
	if (itr != container.end())
		std::cout << "Element " << n << " is present at index " << std::distance(container.begin(), itr) << " in the given container" << std::endl;
	else
		std::cout << "Element " << n << " is not present in the given container" << std::endl;
}

#endif