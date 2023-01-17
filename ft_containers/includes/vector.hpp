#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "containers.hpp"
#include <memory>

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

			while (n--)
				this->_alloc.construct(this->_finish++, val);
		}

		template <class InputIterator> 
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) 
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) {
			difference_type n = ft::distance(first, last);
			this->_start = this->_alloc.allocate(n);
			this->_finish = this->_start;
			this->_end = this->_start + n;
			
			while (n--)
				this->_alloc.construct(this->_finish++, *first++);
		}

		vector (const vector& x)
		: _alloc(x._alloc), _start(NULL), _finish(NULL), _end(NULL) {
			difference_type n = x._finish - x._start;
			this->_start =  this->_alloc.allocate(n);
			this->_finish = this->_start;
			pointer tmp = x._start;

			while (n--)
				this->_alloc.construct(this->_finish++, *tmp++);
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
				erase(begin() + n, end());
			else
				insert(end(), n - size(), val);
		}

		size_type capacity() const {
			return (size_type(this->_end - this->_start));
		}

		bool empty() const {
			return (begin() == end());
		}

		void reserve (size_type n) { // WIP
			if (n > this->max_size())
				throw std::length_error("ft::vector::reserve");
			if (this->capacity() < n) {
				//pointer tmp = allocate_and_copy(n, this->_start, this->_finish);
				pointer tmp_start = this->_start;
				pointer tmp_finish = this->_finish;
				pointer tmp_end = this->_end;

				this->_start = this->_alloc.allocate(n);
				this->_finish = this->_start;
				this->_end = this->_start + n;
				pointer tmp = tmp_start;

				while (tmp != tmp_finish) {
					this->_alloc.construct(this->_finish++, *tmp);
					this->_alloc.destroy(tmp++);
				}
				this->_alloc.deallocate(tmp_start, tmp_end - tmp_start);
			}
		}

		reference operator[] (size_type n) {
			return (*(this->_start + n));
		}
		
		const_reference operator[] (size_type n) const {
			return (*(this->_start + n));
		}

		reference at (size_type n) {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at");
			
			return ((*this)[n]);
		}
		
		const_reference at (size_type n) const {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at");

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
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
			this->clear();
			size_type n = ft::distance(first, last);
			if (n <= this->capacity()) {
				while (n--)
					this->_alloc.construct(this->_finish++, *first++);
			}
			else {
				pointer tmp_start = this->_start;
				pointer tmp_end = this->_end;

				this->_start = this->_alloc.allocate(n);
				this->_finish = this->_start;
				this->_end = this->_start + n;
				const_pointer tmp = &(*first);
				while (tmp != &(*last))
					this->_alloc.construct(this->_finish++, *tmp++);
				this->_alloc.deallocate(tmp_start, tmp_end - tmp_start);			
			}
			// iterator cur(begin());  // OB

			// while (first != last && cur != end()) {
			// 	*cur = *first;
			// 	if (first == last)
			// 		erase(cur, end());
			// 	else
			// 		insert(end(), first, last);
			// 	++cur;
			// 	++first;
			// }
		}

		void assign (size_type n, const value_type& val) {
			this->clear();

			if (n <= this->capacity()) {
				while (n--)
					this->_alloc.construct(this->_finish++, val);
			}
			else {
				pointer tmp_start = this->_start;
				pointer tmp_end = this->_end;

				this->_start = this->_alloc.allocate(n);
				this->_finish = this->_start;
				this->_end = this->_start + n;
				while (n--)
					this->_alloc.construct(this->_finish++, val);
				this->_alloc.deallocate(tmp_start, tmp_end - tmp_start);

			}
			// if (n > capacity()) {
			// 	vector tmp(n, val, this->_alloc);
			// 	tmp.swap(*this);
			// }
			// else {
			// 	// std::fill(begin(), end(), val);
			// 	// std::uninitialized_fill_n(end(), n - size(), val);  // OB
			// 	// this->_finish += n - size();
			// 	while (n--)
			// 		this->_alloc.allocate(this->_finish++, val);
			// }
		}

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

		iterator insert (iterator position, const value_type& val) {
			const size_type n = position - begin();
			this->insert(position, 1, val);
			return (begin() + n);
		}

		void insert (iterator position, size_type n, const value_type& val) {
			if (this->size() + n <= this->capacity()) { // 공간 그대로
				pointer val_tmp = this->_finish;
				size_type after_elems = this->_finish - &(*position);
				this->_finish += n;
				pointer tmp = this->_finish;
				while (after_elems--)
					this->_alloc.construct(--tmp, *(--val_tmp));
				while (n--)
					this->_alloc.construct(--tmp, val);
			}
			else {
				pointer tmp = this->_start;
				size_type _size = n + this->size();
				size_type front = &(*position) - this->_start;
				size_type back = this->_finish - &(*position);
				this->_start = this->_alloc.allocate(_size);
				this->_finish = this->_start;
				this->_end = this->_start + _size;
				while (front--)
				{
					this->_alloc.construct(this->_finish++, *tmp);
					this->_alloc.destroy(tmp++);
				}
				while (n--)
					this->_alloc.construct(this->_finish++, val);
				while (back--) {
					this->_alloc.construct(this->_finish++, *tmp);
					this->_alloc.destroy(tmp++);
				}
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = NULL) {
			for (; first != last; ++first) {
				position = insert(position, *first);
				++position;
			}
		}

		iterator erase (iterator position) {
			if (position + 1 != end())
				std::copy(position + 1, end(), position);
			--this->_finish;
			this->_alloc.destroy(this->_finish);
			return (position);
		}

		iterator erase (iterator first, iterator last) {
			if (last != end())
				std::copy(last, end(), first);
			pointer pos = first.base() + (end() - last); 
			// std::_Destroy(pos, this->_finish, this->_alloc);
			// this->_finish = pos;
			while (pos != this->_finish)
				this->_alloc.destroy(this->_finish--);
			return (first);
		}

		void swap (vector& x) { // OB
			pointer tmp_start = this->_start; 
			this->_start = x._start;
			x._start = tmp_start;

			pointer tmp_finish = this->_finish;
			this->_finish = x._finish;
			x._finish = tmp_finish;

			pointer tmp_end = this->_end;
			this->_end = x._end;
			x._end = tmp_end;

			if (this->_alloc != x._alloc) {
				allocator_type tmp_alloc = this->_alloc;
				this->_alloc = x._alloc;
				x._alloc = tmp_alloc;
			}
		}

		void clear() {
			while (this->_start != this->_finish)
				this->_alloc.destroy(--this->_finish);
		}

		/* ALLOCATOR */
		allocator_type get_allocator() const {
			return (this->_alloc);
		}
	};

	template <class T, class Alloc>
	bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>  
	bool operator> (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T, Alloc>& x, vector<T, Alloc>& y) {
		x.swap(y);
	}

}

#endif