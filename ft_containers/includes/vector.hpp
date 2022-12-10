#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "containers.hpp"
#include <memory>

namespace ft 
{
    
	template < class _T, class _Alloc = std::allocator<_T> >  // generic template
	class _vector {

		/* MEMBER TYPES */
		typedef _T											value_type;
		typedef _Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;

		/* MEMBER FUNCTIONS */
		explicit _vector (const _Alloc& alloc = allocator_type());
		explicit _vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator> _vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		_vector (const vector& x);

		~_vector();
		_vector& operator=(const _vector& v);
	};

}

#endif