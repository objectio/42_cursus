/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:48:06 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:48:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &other) : std::stack<T>(other) {};
	MutantStack &operator=( MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return (*this);
	};
	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin(void)
	{
		return (this->c.begin());
	};
	const_iterator cbegin(void)
	{
		return (this->c.cbegin());
	};
	iterator end(void)
	{
		return (this->c.end());
	};
	const_iterator cend(void)
	{
		return (this->c.cend());
	};
};

#endif