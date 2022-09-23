/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:49:31 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:49:31 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _span(std::vector<int>(0)), _N(0) {}

Span::Span(const unsigned int N) : _span(std::vector<int>()), _N(N) {}

Span::Span(const Span &other) : _N(other._N)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (other._span.size() > _N)
		throw Span::SpanOverflow();
	_span = other._span;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_span.size() + 1 > _N)
		throw Span::SpanOverflow();
	_span.push_back(n);
}

unsigned int Span::shortestSpan(void) const
{
	if (_span.size() < 2)
		throw Span::CannotFindDistance();
	unsigned int shortest = UINT_MAX;
	std::vector<int> sorted(_span);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator itr = sorted.begin();
	while (itr + 1 != sorted.end() && shortest)
	{
		if (static_cast<unsigned int>(*(itr + 1) - *(itr)) < shortest)
			shortest = *(itr + 1) - *(itr);
		itr++;
	}
	return (shortest);
}

unsigned int Span::longestSpan(void) const
{
	if (_span.size() < 2)
		throw Span::CannotFindDistance();
	std::vector<int> sorted(_span);
	std::sort(sorted.begin(), sorted.end());
	return ((*(sorted.end() - 1) - *(sorted.begin())));
}

void Span::addRangeNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end - begin > _N)
		throw Span::SpanOverflow();
	_span.insert(_span.begin(), begin, end);
}

void Span::printSpan(void)
{
	std::vector<int>::iterator begin = _span.begin();
	while (begin < _span.end())
		std::cout << *(begin++) << std::endl;
}

char const *Span::SpanOverflow::what() const throw()
{
	return ("span overflow");
}

char const *Span::CannotFindDistance::what() const throw()
{
	return ("cannot find distance");
}