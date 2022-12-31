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
		allocator_type	_alloc;
		pointer			_start;
		pointer			_finish;
		pointer			_end;

		/* MEMBER FUNCTIONS */
		public:
		explicit vector (const Alloc& alloc = allocator_type())
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) { }

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) {
			this->_start = this->_alloc.allocate(n);
			this->_finish = this->_start;
			this->_end = this->_start + n;

			for (; n > 0; --n; ++this->_finish)
				this->_alloc.construct(this->_finish, val);
		}

		template <class InputIterator> 
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0) 
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) {
			difference_type n = ft::distance(first, last);
			this->_start = this->_alloc.allocate(n);
			this->_finish = this->start;
			this->_end = this->_start + n;
			
			for (; n > 0; --n; ++this->_finish)
				this->_alloc.construct(this->_finish, **first++);
		}

		vector (const vector& x)
		: _alloc(x._alloc), _start(x._start), _finish(x._finish), _end(x._end) {
			difference_type n = x._finish - x._start;
			this->_start =  this->_alloc.allocate(n);
			this->_finish = this->start;
			pointer tmp = x._start;

			for (; n > 0; --n; ++this->_finish)
				this->_alloc.construct(this->_finish, **tmp++);
			this->_end = this->_finish;
		}

		~vector() {
			this->clear();
			this->_alloc.deallocate(this->_start, this->_end - this->_start);
		}

		vector& operator=(const vector& v) {
			if (this != &v) {
				this->clear();
				this->assign(v.begin(), v.end());
			}
			return (*this);
		}
	};

}

#endif