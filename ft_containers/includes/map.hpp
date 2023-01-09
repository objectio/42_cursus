#ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>> >
	class map {
		/* MEMBER TYPES */
		public:
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef ft::pair<const Key, T>	value_type;
		typedef Compare					key_compare;
		typedef Alloc					allocator_type;

		private:
		typedef typename Alloc:value_type	Alloc_value_type;

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
		typedef typename Alloc::template rebind<value_type>::other Pair_alloc_type;
		
	};
}

#endif