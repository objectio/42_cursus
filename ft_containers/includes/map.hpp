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
	};
}

#endif