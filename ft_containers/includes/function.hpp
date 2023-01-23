#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "containers.hpp"
#include "utility.hpp"

namespace ft {
	template <class Pair>
	struct Select1st : public std::unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type& operator()(Pair& x) const {
			return (x.first);
		}

		const typename Pair::first_type& operator()(const Pair& x) const {
			return (x.first);
		}
	};

	template <class T>
	struct Identity : public std::unary_function<T, T>
	{
		T& operator()(T& x) const {
			return (x);
		}

		const T& operator()(const T& x) const {
			return (x);
		}
	};
}

#endif