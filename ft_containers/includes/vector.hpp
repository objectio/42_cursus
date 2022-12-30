#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "containers.hpp"
#include <memory>
#include <vector>

namespace ft 
{
	template <class T, class Alloc = std::allocator<T> >  // generic template
	class vector {

		/* MEMBER TYPES */
		public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::normal_iterator<pointer> 				iterator;
		typedef ft::normal_iterator<const_pointer>			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		/* DATA MEMBERS */
		private:
		allocator_type	alloc;
		pointer			start;
		pointer			finish;
		pointer			end;

		/* MEMBER FUNCTIONS */
		// explicit vector (const Alloc& alloc = allocator_type()) {}
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {}
		// template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		// vector (const vector& x);

		virtual ~vector();
		vector& operator=(const vector& v);
	};

}

#endif