#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include "containers.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
		template <typename T1, typename C1>
		friend bool operator==(const stack<T1, C1>&, const stack<T1, C1>&);

		template <typename T1, typename C1>
		friend bool operator<(const stack<T1, C1>&, const stack<T1, C1>&);

	  public:
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef Container							container_type;

	  protected:
		container_type c;

	  public:
		/*
		 * @brief Default constructor creates no elements.
		 */
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) { }

		// Returns true if the %stack is empty.
		bool empty() const {
			return (c.empty());
		}

		// Returns the number of elements in the %stack.
		size_type size() const {
			return (c.size());
		}

		//
		value_type& top() {
			return (c.back());
		}

		const value_type& top() const {
			return (c.back());
		}

		void push (const value_type& val) {
			c.push_back(val);
		}

		void pop() {
			c.pop_back();
		}
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs < rhs);
	}
}

#endif