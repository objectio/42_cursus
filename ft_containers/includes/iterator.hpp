#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "containers.hpp"

#include <cstddef>

namespace ft 
{
	template < class Category,		// iterator::iterator_category          
	class T,						// iterator::value_type          
	class Distance = ptrdiff_t,		// iterator::difference_type, result of pointer subtraction
	class Pointer = T*,				// iterator::pointer          
	class Reference = T& >			// iterator::reference          
	class iterator {
	public:
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
  };

  template <class Iterator> 
  class iterator_traits {
	public:
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
  };

  template <class T> 
  class iterator_traits<T*> {
	public:
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
  };

  template <class T> 
  class iterator_traits<const T*> {
	public:
	typedef ptrdiff_t							difference_type;
	typedef T									value_type;
	typedef const T*							pointer;
	typedef const T&							reference;
	typedef std::random_access_iterator_tag		iterator_category;
  };

/*******************
* reverse_iterator *
*******************/
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

		reference operator*() const {
			iterator_type tmp = current;
			--tmp;
			return (*tmp);
		}

		reverse_iterator operator+ (difference_type n) const {
			return (reverse_iterator(current - n));
		}

		reverse_iterator& operator++() {
			--current;
			return (*this);
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--current;
			return (tmp);
		}

		reverse_iterator& operator+= (difference_type n) {
			current -= n;
			return (*this);
		}

		reverse_iterator operator- (difference_type n) const {
			return (reverse_iterator(current + n));
		}

		reverse_iterator& operator--() {
			++current;
			return (*this);
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++current;
			return (tmp);
		}

		reverse_iterator& operator-= (difference_type n) {
			current += n;
			return (*this);
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return (*(*this + n));
		}
  };

  template <class IteratorL, class IteratorR>
  bool operator== (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() == rhs.base());
  }

  template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
  }

  template <class IteratorL, class IteratorR>
  bool operator!= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() != rhs.base());
  }

  template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
  }

  template <class IteratorL, class IteratorR>
  bool operator< (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() > rhs.base());
  }

  template <class Iterator>
  bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
  }

  template <class IteratorL, class IteratorR>
  bool operator<= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() >= rhs.base());
  }

  template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
  }

  template <class IteratorL, class IteratorR>
  bool operator> (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() < rhs.base());
  }

  template <class Iterator>
  bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
  }

  template <class IteratorL, class IteratorR>
  bool operator>= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() <= rhs.base());
  }

  template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
  }

  template <class Iterator>
  reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	return (reverse_iterator<Iterator>(rev_it.base() - n));
  }

  template <class IteratorL, class IteratorR>
  typename reverse_iterator<IteratorL>::difference_type operator- (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (rhs.base() - lhs.base());
  }

  template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (rhs.base() - lhs.base());
  }

	template<class Iterator>
	typename iterator_traits<Iterator>::difference_type distance (Iterator first, Iterator last) {
		typename iterator_traits<Iterator>::difference_type cnt = 0;

		while (first != last) {
			first++;
			cnt++;
		}
		return (cnt);
	}
}

#endif