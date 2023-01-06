#ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"

namespace ft {
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key, T>> >        
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
	};
}

#endif