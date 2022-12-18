/***********************************************************************

 * is_integral
 * enable_if

***********************************************************************/

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include "containers.hpp"

namespace ft 
{
    template <class T, T v>
	struct integral_constant 
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator value_type() const { return v; }
	};

	template <class T>
	struct is_integral : public ft::integral_constant<bool, false> {};
	
	template <>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<short int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
}

#endif