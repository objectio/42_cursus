#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "containers.hpp"
#include <memory>

namespace ft 
{
    
	template <class _T, class _Allocator = std::allocator<_T> >
	class vector {
		vector() {}
		~vector() {}
		vector& operator=(const vector& v);
	};

}

#endif