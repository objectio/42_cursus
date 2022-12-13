#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft 
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag			: public input_iterator_tag {};
	struct bidirectional_iterator_tag	: public forward_iterator_tag {};
	struct random_access_iterator_tag	: public bidirectional_iterator_tag {};

	template < class Category,		// iterator::iterator_category          
	class T,						// iterator::value_type          
	class Distance = ptrdiff_t,		// iterator::difference_type, result of pointer subtraction
	class Pointer = T*,				// iterator::pointer          
	class Reference = T& >			// iterator::reference          
	class iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
  };

  template <class Iterator> 
  class iterator_traits {
	typedef Iterator::difference_type	difference_type;
	typedef Iterator::value_type		value_type;
	typedef Iterator::pointer			pointer;
	typedef Iterator::reference			reference;
	typedef Iterator::iterator_category	iterator_category;
  };

  template <class T> 
  class iterator_traits<T*> {
	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef random_access_iterator_tag	iterator_category;
  };

  template <class T> 
  class iterator_traits<const T*> {
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef random_access_iterator_tag		iterator_category;
  };

	template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		T* p;

		public:
		random_access_iterator(T* t) : p(t) {}
		random_access_iterator(const T& t) : p(t.p) {}
		~random_access_iterator() {}
		random_access_iterator& operator++() {
			++p;
			return *this;
		}
		random_access_iterator operator++(T) {
			random_access_iterator tmp(*this);
			operator++();
			return tmp;
		}
		bool operator==(const random_access_iterator& rhs) const {
			return p == rhs.p;
		}
		bool operator!=(const random_access_iterator& rhs) const {
			return p != rhs.p;
		}
		T& operator*() {
			return *p;
		}
	};
}

#endif