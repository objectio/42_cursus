/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:47:15 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:47:15 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

class Span
{
	public:
	Span();
	Span(const unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
	void addRangeNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void printSpan(void);

	class SpanOverflow : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	
	class CannotFindDistance : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	private:
	std::vector<int>			_span;
	const unsigned int			_N;
};

#endif