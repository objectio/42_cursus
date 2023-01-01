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
			
			for (; first != last; ++first; ++this->_finish)
				this->_alloc.construct(this->_finish, *first);
		}

		vector (const vector& x)
		: _alloc(x._alloc), _start(x._start), _finish(x._finish), _end(x._end) {
			difference_type n = x._finish - x._start;
			this->_start =  this->_alloc.allocate(n);
			this->_finish = this->start;
			this->_end = this->_start + n;

			for (size_type i = 0; i < n; ++i, ++this->_finish)
				this->_alloc.construct(this->_finish, *(x._start + i));
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

		/* ITERATORS */
		iterator begin() {
			return (iterator(this->_start));
		}

		const_iterator begin() const {
			return (const_iterator(this->_start));
		}

		iterator end() {
			return (iterator(this->_finish));
		}
		
		const_iterator end() const {
			return (const_iterator(this->_finish));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}
		 
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

		size_type size() const {
			return (size_type(this->_finish - this->_start));
		}

		size_type max_size() const {
			return (this->_alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < size())
				erase(this->_start + n);
			else
				insert(end(), n - size(), val);
		}

		size_type capacity() const {
			return (size_type(this->_end - this->_start));
		}

		bool empty() const {
			return (begin() == end());
		}

		void reserve (size_type n); // WIP

		reference operator[] (size_type n) {
			return (*(this->_start + n));
		}
		
		const_reference operator[] (size_type n) const {
			return (*(this->_start + n));
		}

		reference at (size_type n) {
			if (n >= this->size())
				std::out_of_range("ft::vector::at");
			
			return ((*this)[n]);
		}
		
		const_reference at (size_type n) const {
			if (n >= this->size())
				std::out_of_range("ft::vector::at");

			return ((*this)[n]);
		}

		reference front() {
			return (*begin());
		}
		
		const_reference front() const {
			return (*begin());
		}

		reference back() {
			return (*(end() - 1));
		}
		
		const_reference back() const {
			return (*(end() - 1));
		}

		pointer data() {
			return (pointer(this->_start));
		}

		const_pointer data() const {
			return (const_iterator(this->_start));
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			typedef typename ft::is_integral<InputIterator>::type _integral;
			// WIP
		}

		void assign (size_type n, const value_type& val); // WIP

		void push_back (const value_type& val) {
			if (this->_finish != this->_end)
			{
				this->_alloc.construct(this->_finish, val);
				++this->_finish;
			}
			else {
				if (this->size() == 0)
					this->reserve(1);
				else
					this->reserve(2 * this->capacity());
			}
		}

		void pop_back() {  // size() 검사 할까말까
			--this->_finish;
			this->_alloc.destroy(this->_finish);
		}

		iterator insert (iterator position, const value_type& val);

		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (vector& x);

		void clear();
	};

}

#endif