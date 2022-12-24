#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "containers.hpp"

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
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
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

  template <class Iterator> 
  class reverse_iterator
  {
	  public:
	  	typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
	
	  protected:
	  	iterator_type current;

	  public:
		reverse_iterator() : current() {}
		
		explicit reverse_iterator (iterator_type it) : current(it) {}
		
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {}

		virtual ~reverse_iterator() {}

		iterator_type base() const {
			return current;
		}
  };
}

#endif