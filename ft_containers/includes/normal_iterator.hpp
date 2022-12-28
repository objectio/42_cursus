#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "containers.hpp"

namespace ft
{
	template <class Iterator> 
	class normal_iterator {
		protected:
		Iterator current;

		public:
		typedef Iterator										iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

		normal_iterator() : current() {}

		explicit normal_iterator(const iterator_type& it) : current(it) {}

		template <typename Iter>
		normal_iterator(const normal_iterator<Iter>& rev_it) : current(rev_it.base()) {}

		reference operator* () const {
			return (*current);
		}

		pointer operator->() const {
			return current; 
		}

		normal_iterator& operator++() {
			++current;
			return (*this);
		}

		normal_iterator operator++(int) {
			return (normal_iterator(current++));
		}

		normal_iterator& operator--() {
			--current;
			return (*this);
		}

		normal_iterator operator--(int) {
			return (normal_iterator(current--));
		}

		reference operator[] (const difference_type& n) const {
			return (current[n]);
		}

		normal_iterator& operator+= (const difference_type& n) {
			current += n;
			return (*this);
		}

		normal_iterator operator+ (const difference_type& n) const {
			return (normal_iterator(current + n));
		}

		normal_iterator& operator-= (const difference_type& n) {
			current -= n;
			return (*this);
		}

		normal_iterator operator- (const difference_type& n) const {
			return (normal_iterator(current - n));
		}

		const iterator_type& base() const {
			return (current);
		}
	};
}

#endif