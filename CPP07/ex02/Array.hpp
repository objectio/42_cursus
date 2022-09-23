/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:38:14 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:38:14 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
	public:
	Array(void) : _array(new T[0]), _size(0) {};
	Array(unsigned int n) : _array(new T[n]), _size(n) {};
	Array(const Array &other) : _array(NULL)
	{
		*this = other;
	};
	Array & operator=(const Array & other)
	{
		if (_array)
			delete [] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = *other._array;
		return (*this);
	};
	~Array(void)
	{
		if (_array)
			delete [] _array;
	};

	T & operator[](int index)
	{
		if (index < 0)
			throw Array::IndexTooLow();
		else if (index >= static_cast<int>(_size))
			throw Array::IndexTooHigh();

		return (_array[index]);
	};

	class IndexTooHigh : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Exception : Index is out of range : Too high !");
		};
	};

	class IndexTooLow : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Exception : Index is out of range : Too low !");
		};
	};

	unsigned int size(void) const
	{
		return (_size);
	};
	
	T & browse(int index) const
	{
		return (_array[index]);
	};

	void display(void) const
	{
		std::cout << "[ ";
		for (unsigned int i = 0; i < _size; i++)
		{
			std::cout << browse(i);
			if (i != _size - 1)
				std::cout << ", ";
		}
		std::cout << " ]" << std::endl;
	};

	private:
	T *				_array;
	unsigned int	_size;
};

#endif