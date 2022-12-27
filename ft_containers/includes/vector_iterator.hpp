#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "containers.hpp"

namespace ft
{
	template <class Iterator> 
	class vector_iterator {
		public:
		typedef Iterator										iterator_type;
		typedef iterator_traits<Iterator>::difference_type		difference_type;
		typedef iterator_traits<Iterator>::value_type			value_type;
		typedef iterator_traits<Iterator>::pointer				pointer;
		typedef iterator_traits<Iterator>::reference			reference;
		typedef iterator_traits<Iterator>::iterator_category	iterator_category
	};
}

#endif