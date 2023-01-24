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
		/*
		 * @brief	Default constructor creates no elements.
		 */
		explicit vector (const Alloc& alloc = allocator_type())
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) { }

		/*
		 * @brief	Create a %vector with copies of an exemplar element.
		 * @param	n	The number of elements to initially create.
		 * @param	val	An element to copy.
		 */
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _start(NULL), _finish(NULL), _end(NULL) {
			this->_start = this->_alloc.allocate(n);
			this->_finish = this->_start;
			this->_end = this->_start + n;

			while (n--)
				this->_alloc.construct(this->_finish++, val);
		}

		/*
		 * @brief	Builds a %vector from a range.
		 * @param	first	An input iterator.
		 * @param	last	An input iterator.
		 */
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

		/*
		 * @brief	%Vector copy constructor.
		 * @param	x	A %vector of identical element and allocator types.
		 */
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

		/*
		 * @brief	%Vector assignment operator.
		 * @param	v	A %vector of identical element and allocator types.
		 */
		vector& operator=(const vector& v) {
			if (this != &v) {
				this->clear();
				this->assign(v.begin(), v.end());
			}
			return (*this);
		}

		/* ITERATORS */
		// Returns a read/write iterator that points to the first element in the %vector.
		// Iteration is done in ordinary element order.
		iterator begin() {
			return (iterator(this->_start));
		}

		// Returns a read-only (constant) iterator that points to the first element in the %vector.
		// Iteration is done in ordinary element order.
		const_iterator begin() const {
			return (const_iterator(this->_start));
		}

		// Returns a read/write iterator that points one past the last element in the %vector.
		// Iteration is done in ordinary element order.
		iterator end() {
			return (iterator(this->_finish));
		}

		// Returns a read-only (constant) iterator that points one past the last element in the %vector.
		// Iteration is done in ordinary element order.		
		const_iterator end() const {
			return (const_iterator(this->_finish));
		}

		// Returns a read/write reverse iterator that points to the last element in the %vector.
		// Iteration is done in reverse element order.
		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}

		// Returns a read-only (constant) reverse iterator that points to the last element in the %vector.
		// Iteration is done in reverse element order.
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}

		// Returns a read/write reverse iterator that points to one before the first element in the %vector.
		// Iteration is done in reverse element order.
		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		// Returns a read-only (constant) reverse iterator that points to one before the first element in the %vector.
		// Iteration is done in reverse element order.
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

		// Returns the number of elements in the %vector.
		size_type size() const {
			return (size_type(this->_finish - this->_start));
		}

		// Returns the size() of the largest possible %vector.
		size_type max_size() const {
			return (this->_alloc.max_size());
		}

		/*
		 * @brief	Resizes the %vector to the specified number of elements.
		 * @param	n	Number of elements the %vector should contain.
		 * @param	val	Data with which new elements should be populated.
		 * 
		 * n의 capacity를 미리 확보해놓고 나머지 공간을 val의 값으로 채운다.
		 */
		void resize (size_type n, value_type val = value_type()) {
			if (n < size())
				erase(begin() + n, end());
			else
				insert(end(), n - size(), val);
		}

		// Returns the total number of elements that the %vector can hold before needing to allocate more memory.
		size_type capacity() const {
			return (size_type(this->_end - this->_start));
		}

		// Returns true if the %vector is empty. (Thus begin() would equal end().)
		bool empty() const {
			return (begin() == end());
		}

		/*
		 * @brief	Attempt to preallocate enough memory for specified number of elements.
		 * @param	n	Number of elements required.
		 * @throw	std::length_error	If @a n exceeds @c max_size().
		 * 
		 * push_back()을 쓸 때 당시의 capacity를 초과하는 양이 들어가게 된다면 다시 할당을 하고 기존의 메모리는 해제한다. 
		 * 즉 이 작업 속에는 할당-복사-해제 단계를 거치게 되어 비용이 많이 들어가게 되고, 그만큼 성능이 떨어진다.
		 * 이를 방지하기 위해서는 유저가 벡터에 필요하다고 여겨지는 크기만큼을 미리 할당시켜주는 것이다.
		 * 미리 할당해주는 함수는 reserve와 resize가 있는데, reserve는 공간을 초기화시키지 않는다. 
		 */
		void reserve (size_type n) {
			if (n > this->max_size())
				throw std::length_error("ft::vector::reserve");
			if (this->capacity() < n) {
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

		/*
		 * @brief	Subscript access to the data contained in the %vector.
		 * @param	n	The index of the element for which data should be accessed.
		 * @return	Read/write reference to data.
		 */
		reference operator[] (size_type n) {
			return (*(this->_start + n));
		}

		/*
		 * @brief	Subscript access to the data contained in the %vector.
		 * @param	n	The index of the element for which data should be accessed.
		 * @return	Read-only (constant) reference to data.
		 */
		const_reference operator[] (size_type n) const {
			return (*(this->_start + n));
		}

		/*
		 * @brief	Provides access to the data contained in the %vector.
		 * @param	n	The index of the element for which data should be accessed.
		 * @return	Read/write reference to data.
		 * @throw	std::out_of_range	If @a n is an invalid index.
		 * 
		 * This function provides for safer data access. 
		 * The parameter is first checked that it is in the range of the vector.
		 * The function throws out_of_range if the check fails.
		 */
		reference at (size_type n) {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at");
			
			return ((*this)[n]);
		}

		/*
		 * @brief	Provides access to the data contained in the %vector.
		 * @param	n	The index of the element for which data should be accessed.
		 * @return	Read-only (constant) reference to data.
		 * @throw	std::out_of_range	If @a n is an invalid index.
		 *
		 * This function provides for safer data access. 
		 * The parameter is first checked that it is in the range of the vector.
		 * The function throws out_of_range if the check fails.
		 */
		const_reference at (size_type n) const {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at");

			return ((*this)[n]);
		}

		// Returns a read/write reference to the data at the first element of the %vector.
		reference front() {
			return (*begin());
		}

		// Returns a read-only (constant) reference to the data at the first element of the %vector.
		const_reference front() const {
			return (*begin());
		}

		// Returns a read/write reference to the data at the last element of the %vector.
		reference back() {
			return (*(end() - 1));
		}

		// Returns a read-only (constant) reference to the data at the last element of the %vector.
		const_reference back() const {
			return (*(end() - 1));
		}

		// Returns a pointer such that [data(), data() + size()) is a valid range.
		// For a non-empty %vector, data() == &front().
		pointer data() {
			return (pointer(this->_start));
		}

		const_pointer data() const {
			return (const_iterator(this->_start));
		}

		/*
		 * @brief	Assigns a range to a %vector.
		 * @param	first	An input iterator.
		 * @param	last	An input iterator.
		 */
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
		}

		/*
		 * @brief	Assigns a given value to a %vector.
		 * @param	n	Number of elements to be assigned.
		 * @param	val	Value to be assigned.
		 */
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
		}

		/*
		 * @brief	Add data to the end of the %vector.
		 * @param	x	Data to be added.
		 * 
		 * This is a typical stack operation.
		 */
		void push_back (const value_type& val) {
			if (this->_finish == this->_end) {
				if (this->size() == 0)
					this->reserve(1);
				else
					this->reserve(2 * this->capacity());
			}
				this->_alloc.construct(this->_finish, val);
				++this->_finish;
		}

		/*
		 * @brief	Removes last element.
		 * 
		 * This is a typical stack operation. It shrinks the %vector by one.
		 */
		void pop_back() {
			--this->_finish;
			this->_alloc.destroy(this->_finish);
		}

		/*
		 * @brief	Inserts given value into %vector before specified iterator.
		 * @param	position	An iterator into the %vector.
		 * @param	val	Data to be inserted.
		 * @return	An iterator that points to the inserted data.
		 */
		iterator insert (iterator position, const value_type& val) {
			const size_type n = position - begin();
			this->insert(position, 1, val);
			return (begin() + n);
		}

		/*
		 * @brief	Inserts a number of copies of given data into the %vector.
		 * @param	position	An iterator into the %vector.
		 * @param	n	Number of elements to be inserted.
		 * @param	val	Data to be inserted.
		 * @return	An iterator that points to the inserted data.
		 */
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

		/*
		 * @brief	Inserts a range into the %vector.
		 * @param	position	An iterator into the %vector.
		 * @param	first	An input iterator.
		 * @param	last	An input iterator.
		 */
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = NULL) {
			for (; first != last; ++first) {
				position = insert(position, *first);
				++position;
			}
		}

		/*
		 * @brief	Remove element at given position.
		 * @param	position	Iterator pointing to element to be erased.
		 * @return	An iterator pointing to the next element (or end()).
		 */
		iterator erase (iterator position) {
			if (position + 1 != end())
				std::copy(position + 1, end(), position);
			--this->_finish;
			this->_alloc.destroy(this->_finish);
			return (position);
		}

		/*
		 * @brief	Remove a range of elements.
		 * @param	first	Iterator pointing to the first element to be erased.
		 * @param	last	Iterator pointing to one past the last element to be erased.
		 * @return	An iterator pointing to the element pointed to by @a last prior to erasing (or end()). 
		 * 
		 * This function will erase the elements in the range [first,last) and shorten the %vector accordingly.
		 */
		iterator erase (iterator first, iterator last) {
			if (last != end())
				std::copy(last, end(), first);
			pointer pos = first.base() + (end() - last); 
			while (pos != this->_finish)
				this->_alloc.destroy(this->_finish--);
			return (first);
		}

		/*
		 * @brief	Swaps data with another %vector.
		 * @param	x	A %vector of the same element and allocator types.
		 */
		void swap (vector& x) {
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

		// Erases all the elements.
		void clear() {
			while (this->_start != this->_finish)
				this->_alloc.destroy(--this->_finish);
		}

		/* ALLOCATOR */
		// Get a copy of the memory allocation object.
		allocator_type get_allocator() const {
			return (this->_alloc);
		}
	};

	/*
	 * @brief	Vector equality comparison.
	 * @param	lhs	A %vector.
	 * @param	rhs	A %vector of the same type as @a x.
	 * @return	True if the size and elements of the vectors are equal.
	 */
	template <class T, class Alloc>
	bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	/*
	 * @brief	Vector ordering relation.
	 * @param	lhs	A %vector.
	 * @param	rhs	A %vector of the same type as @a x.
	 * @return	True if @a x is lexicographically less than @a y.
	 */
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