#ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
#include "utility.hpp"
#include "rbtree.hpp"
#include "function.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		/* MEMBER TYPES */
		public:
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef ft::pair<const Key, T>	value_type;
		typedef Compare					key_compare;
		typedef Alloc					allocator_type;

		private:
		typedef typename Alloc::value_type	Alloc_value_type;

		public:
		class value_compare : public std::binary_function<value_type, value_type, bool> {
			friend class map<Key, T, Compare, Alloc>;

			protected:
			Compare comp;
			value_compare(Compare c) : comp(c) { }

			public:
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

		private:
		typedef typename Alloc::template rebind<value_type>::other	Pair_alloc_type;
		typedef Rb_tree<key_type, value_type, ft::Select1st<value_type>, key_compare, Pair_alloc_type>	Rep_type;
		Rep_type	m_t;

		public:
		typedef typename Pair_alloc_type::pointer			pointer;
		typedef typename Pair_alloc_type::const_pointer		const_pointer;
		typedef typename Pair_alloc_type::reference			reference;
		typedef typename Pair_alloc_type::const_reference	const_reference;
		typedef typename Rep_type::iterator					iterator;
		typedef typename Rep_type::const_iterator			const_iterator;
		typedef typename Rep_type::size_type				size_type;
		typedef typename Rep_type::difference_type			difference_type;
		typedef typename Rep_type::reverse_iterator			reverse_iterator;
		typedef typename Rep_type::const_reverse_iterator	const_reverse_iterator;

		map()
		: m_t(Compare(), allocator_type()) { }

		explicit map(const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) { }

		map(const map& x)
		: m_t(x.m_t) { }

		template <typename InputIterator>
		map(InputIterator first, InputIterator last)
		: m_t(Compare(), allocator_type()) {
			m_t.insert_unique(first, last);
		}

		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) {
			m_t.insert_unique(first, last);
		}

		map& operator=(const map& x) {
			m_t = x.m_t;
			return (*this);
		}

		allocator_type get_allocator() const {
			return m_t.get_allocator();
		}

		iterator begin() {
			return (m_t.begin());
		}

		const_iterator begin() const {
			return (m_t.begin());
		}

		iterator end() {
			return (m_t.end());
		}

		const_iterator end() const {
			return (m_t.end());
		}

		reverse_iterator rbegin() {
			return (m_t.rbegin());
		}

		const_reverse_iterator rbegin() const {
			return (m_t.rbegin());
		}

		reverse_iterator rend() {
			return (m_t.rend());
		}

		const_reverse_iterator rend() const {
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

		mapped_type& operator[](const key_type& k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return ((*i).second);
		}

		mapped_type& at(const key_type& k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::range_error("ft::map::at");
			return ((*i).second);
		}

		const mapped_type& at(const key_type& k) const {
			const_iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::range_error("ft::map::at");
			return ((*i).second);
		}

		ft::pair<iterator, bool> insert(const value_type& x) {
			return (m_t.insert_unique(x));
		}

		iterator insert(iterator position, const value_type& x) {
			return (m_t.insert_unique(position, x));
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			m_t.insert_unique(first, last);
		}

		void erase(iterator position) {
			m_t.erase(position);
		}

		size_type erase(const key_type& x) {
			return (m_t.erase(x));
		}

		void erase(iterator first, iterator last) {
			m_t.erase(first, last);
		}

		void swap(map& x) {
			m_t.swap(x.m_t);
		}

		void clear() {
			m_t.clear();
		}

		key_compare key_comp() const {
			return (m_t.key_comp());
		}

		value_compare value_comp() const {
			return (value_compare(m_t.key_comp()));
		}

		iterator find(const key_type& x) {
			return (m_t.find(x));
		}

		const_iterator find(const key_type& x) const {
			return (m_t.find(x));
		}

		size_type count(const key_type& x) const {
			return (m_t.find(x) == m_t.end() ? 0 : 1);
		}

		iterator lower_bound(const key_type& x) {
			return (m_t.lower_bound(x));
		}

		const_iterator lower_bound(const key_type& x) const {
			return (m_t.lower_bound(x));
		}

		iterator upper_bound(const key_type& x) {
			return (m_t.upper_bound(x));
		}

		const_iterator upper_bound(const key_type& x) const {
			return (m_t.upper_bound(x));
		}

		ft::pair<iterator, iterator> equal_range(const key_type& x) {
			return (m_t.equal_range(x));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type& x) const {
			return (m_t.equal_range(x));
		}

		template <typename _Key, typename _T, typename _Compare, typename _Allocator>
		friend bool operator==(const map<_Key, _T, _Compare, _Allocator>&, const map<_Key, _T, _Compare, _Allocator>&);

		template <typename _Key, typename _T, typename _Compare, typename _Allocator>
		friend bool operator<(const map<_Key, _T, _Compare, _Allocator>&, const map<_Key, _T, _Compare, _Allocator>&);
	};

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (x.m_t == y.m_t);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (x.m_t < y.m_t);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x == y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (x > y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x > y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x < y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y) {
		x.swap(y);
	}
}

#endif