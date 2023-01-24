#ifndef SET_HPP
#define SET_HPP

#include "containers.hpp"
#include "rbtree.hpp"

namespace ft {
	template < class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
	class set {
		typedef typename Alloc::value_type	alloc_value_type;

	  public:
		typedef Key							key_type;
		typedef Key							value_type;
		typedef Compare						key_compare;
		typedef Compare						value_compare;
		typedef Alloc						allocator_type;

	  private:
		typedef typename Alloc::template rebind<Key>::other	key_alloc_type;
		typedef Rb_tree<key_type, value_type, ft::Identity<value_type>, key_compare, key_alloc_type> rep_type;
		rep_type m_t; // red-black tree

	  public:
		typedef typename key_alloc_type::pointer			pointer;
		typedef typename key_alloc_type::const_pointer		const_pointer;
		typedef typename key_alloc_type::reference			reference;
		typedef typename key_alloc_type::const_reference	const_reference;
		typedef typename rep_type::const_iterator			iterator;
		typedef typename rep_type::const_iterator			const_iterator;
		typedef typename rep_type::const_reverse_iterator	reverse_iterator;
		typedef typename rep_type::const_reverse_iterator	const_reverse_iterator;
		typedef typename rep_type::size_type				size_type;
		typedef typename rep_type::difference_type			difference_type;

		//  Default constructor creates no elements.
		set() : m_t(Compare(), allocator_type()) { }

		/*
		 * @brief	Defalut constructor creates no elements.
		 * @param	comp	Comparator to use.
		 * @param	a		Allocator to use.
		 */
		explicit set(const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) { }

		/*
		 * @brief	Builds a %set from a range.
		 * @param	first	An input iterator.
		 * @param	last	An input iterator.
		 */
		template <class InputIterator>
		set(InputIterator first, InputIterator last) : m_t(Compare(), allocator_type()) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @brief	Builds a %set from a range.
		 * @param	first	An input iterator.
		 * @param	last	An input iterator.
		 * @param	comp	A comparison functor.
		 * @param	a		An allocator object.
		 */
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @brief	Set copy constructor.
		 * @param	x	A %set of identical element and allocator types.
		 */
		set(const set<Key, Compare, Alloc>& x) : m_t(x.m_t) { }

		/*
		 * @brief	Set assignment operator.
		 * @param	x	A %set of identical element and allocator types.
		 */
		set<Key, Compare, Alloc>& operator=(const set<Key, Compare, Alloc>& x) {
			m_t = x.m_t;
			return (*this);
		}

		/* ACCESSORS */
		// Returns the comparison object with which the %set was constructed.
		key_compare key_comp() const {
			return (m_t.key_comp());
		}

		//  Returns the comparison object with which the %set was constructed.
		value_compare value_comp() const {
			return (m_t.key_comp());
		}

		//  Returns the allocator object with which the %set was constructed.
		allocator_type get_allocator() const {
			return (m_t.get_allocator());
		}

		// Returns a read/write iterator that points to the first element in the %set.
		// Iteration is done in ascending order according to the keys.
		iterator begin() const {
			return (m_t.begin());
		}

		// Returns a read/write iterator that points one past the last element in the %set.
		// Iteration is done in ascending order according to the keys.
		iterator end() const {
			return (m_t.end());
		}

		// Returns a read/write reverse iterator that points to the last element in the %set.
		// Iteration is done in descending order according to the keys.
		reverse_iterator rbegin() const {
			return (m_t.rbegin());
		}

		// Returns a read-only (constant) reverse iterator that points to the last pair in the %map.
		// Iteration is done in descending order according to the keys.
		reverse_iterator rend() const {
			return (m_t.rend());
		}
		
		// Returns true if the %set is empty.
		bool empty() const {
			return (m_t.empty());
		}

		// Returns the size of the %set.
		size_type size() const {
			return (m_t.size());
		}

		// Returns the maximum size of the %set.
		size_type max_size() const {
			return (m_t.max_size());
		}

		/*
		 * @brief	Attempts to insert an element into the %set.
		 * @param	val	Element to be inserted.
		 * @return	A pair, of which the first element is an iterator that points to the possibly inserted element,
		 * 			and the second is a bool that is true if the element was actually inserted.
		 */
		ft::pair<iterator, bool> insert (const value_type& val) {
			ft::pair<iterator, bool> p = m_t.insert_unique(val);
			return (ft::pair<iterator, bool>(p.first, p.second));
		}

		/*
		 * @brief	Attempts to insert an element into the %set.
		 * @param	position	An iterator that serves as a hint as to where the element should be inserted.
		 * @param	val	Element to be inserted.
		 * @return	An iterator that points to the element with key of @a val (may or may not be the element passed in).
		 */
		iterator insert (iterator position, const value_type& val) {
			return (m_t.insert_unique(position, val));
		}

		/*
		 * @brief	A template function that attemps to insert a range of elements.
		 * @param	first	Iterator pointing to the start of the range to be inserted.
		 * @param	last	Iterator pointing to the end of the range.
		 */
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @brief	Erases an element from a %set.
		 * @param	position	An iterator pointing to the element to be erased.
		 */
		void erase (iterator position) {
			m_t.erase(position);
		}

		/*
		 * @brief	Erases elements according to the provided key.
		 * @param	val	Key of element to be erased.
		 * @return	The number of elements erased.
		 */
		size_type erase (const value_type& val) {
			return (m_t.erase(val));
		}

		/*
		 * @brief	Erases a [first,last) range of elements from a %set.
		 * @param	first	Iterator pointing to the start of the range to be erased.
		 * @param	last	Iterator pointing to the end of the range to be erased.
		 */
		void erase (iterator first, iterator last) {
			m_t.erase(first, last);
		}

		/*
		 * @brief	Swaps data with another %set.
		 * @param	x	A %set of the same element and allocator types.
		 */
		void swap (set& x) {
			m_t.swap(x.m_t);
		}

		// Erases all elements in a %set. 단, 담고 있는 요소가 포인터 변수인 경우는 건드리지 못함. 유저에게 처리를 맡김.
		void clear() {
			m_t.clear();
		}

		/*
		 * @brief	Tries to locate an element in a %set.
		 * @param	val	Element to be located.
		 * @return	Iterator pointing to sought-after(찾고 있는) element, or end() if not found.
		 */
		iterator find (const value_type& val) {
			return (m_t.find(val));
		}

		const_iterator find (const value_type& val) const {
			return (m_t.find(val));
		}

		/*
		 * @brief	Finds the number of elements.
		 * @param	val	Element to located.
		 * @return	Number of elements with specified key.
		 */
		size_type count (const value_type& val) const {
			return (m_t.find(val) == m_t.end() ? 0 : 1);
		}

		/*
		 * @brief	Finds the beginning of a subsequence matching given key.
		 * @param	val	Key to be located.
		 * @return	Iterator pointing to first element equal to or greater than key, or end().
		 */
		iterator lower_bound (const value_type& val) {
			return (m_t.lower_bound(val));
		}

		const_iterator lower_bound (const value_type& val) const {
			return (m_t.lower_bound(val));
		}

		/*
		 * @brief	Finds the end of a subsequence matching given key.
		 * @param	val	Key to be located.
		 * @return	Iterator pointing to first element equal to or greater than key, or end().
		 */
		iterator upper_bound (const value_type& val) {
			return (m_t.upper_bound(val));
		}

		const_iterator upper_bound (const value_type& val) const {
			return (m_t.upper_bound(val));
		}

		/*
		 * @brief	Finds a subsequence matching given key.
		 * @param	val	Key to be located.
		 * @return	Pair of iterators that possibly points to the subsequence matching given key.
		 */
		ft::pair<iterator, iterator> equal_range (const value_type& val) {
			return (m_t.equal_range(val));
		}

		ft::pair<const_iterator, const_iterator> equal_range (const value_type& val) const {
			return (m_t.equal_range(val));
		}

		template <class K1, class C1, class A1>
		friend bool operator==(const set<K1, C1, A1>&, const set<K1, C1, A1>&);

		template <class K1, class C1, class A1>
		friend bool operator<(const set<K1, C1, A1>&, const set<K1, C1, A1>&);
	};

	/*
	 * @brief	Set equality comparison.
	 * @param	x	A %set.
	 * @param	y	A %set of the same type as @a x.
	 * @return	True if the size and elements of the sets are equal.
	 */
	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return (x.m_t == y.m_t);
	}

	/*
	 * @brief	Set ordering relation.
	 * @param	x	A %set.
	 * @param	y	A %set of the same type as @a x.
	 * @return	True if @a x is lexicographically less than @a y.
	 */
	template <class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return (x.m_t < y.m_t);
	 }

	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return !(x == y);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return !(y < x);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return (y < x);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return !(x < y);
	}

	template <class Key, class Compare, class Alloc>
	void swap(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		x.swap(y);
	}
}

#endif