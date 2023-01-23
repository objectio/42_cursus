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

		value_compare value_comp() const {
			return (m_t.key_comp());
		}

		allocator_type get_allocator() const {
			return (m_t.get_allocator());
		}

		iterator begin() const {
			return (m_t.begin());
		}

		iterator end() const {
			return (m_t.end());
		}

		reverse_iterator rbegin() const {
			return (m_t.rbegin());
		}

		reverse_iterator rend() const {
			return (m_t.rend());
		}
		
		bool empty() const {
			return (m_t.empty());
		}

		size_type size() const {
			return (m_t.size());
		}

		size_type max_size() const {
			return (m_t.max_size());
		}

		ft::pair<iterator, bool> insert (const value_type& val) {
			ft::pair<iterator, bool> p = m_t.insert_unique(val);
			return (ft::pair<iterator, bool>(p.first, p.second));
		}

		iterator insert (iterator position, const value_type& val) {
			return (m_t.insert_unique(position, val));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			m_t.insert_unique(first, last);
		}

		void erase (iterator position) {
			m_t.erase(position);
		}

		size_type erase (const value_type& val) {
			return (m_t.erase(val));
		}

		void erase (iterator first, iterator last) {
			m_t.erase(first, last);
		}

		void swap (set& x) {
			m_t.swap(x.m_t);
		}

		void clear() {
			m_t.clear();
		}

		iterator find (const value_type& val) {
			return (m_t.find(val));
		}

		const_iterator find (const value_type& val) const {
			return (m_t.find(val));
		}

		size_type count (const value_type& val) const {
			return (m_t.find(val) == m_t.end() ? 0 : 1);
		}

		iterator lower_bound (const value_type& val) {
			return (m_t.lower_bound(val));
		}

		const_iterator lower_bound (const value_type& val) const {
			return (m_t.lower_bound(val));
		}

		iterator upper_bound (const value_type& val) {
			return (m_t.upper_bound(val));
		}

		const_iterator upper_bound (const value_type& val) const {
			return (m_t.upper_bound(val));
		}

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

	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y) {
		return (x.m_t == y.m_t);
	}

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