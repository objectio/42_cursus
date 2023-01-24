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

		// Returns a read/write reference to the data at the first element of the %stack.
		value_type& top() {
			return (c.back());
		}

		// Returns a read-only (constant) reference to the data at the first element of the %stack.
		const value_type& top() const {
			return (c.back());
		}

		/*
		 * @brief	Add data to the top of the %stack.
		 * @param	val	Data to be added.
		 * 
		 * This is a typical %stack operation.
		 * The function creates an element at the top of the %stack 
		 * and assigns the given data to it.
		 */
		void push (const value_type& val) {
			c.push_back(val);
		}

		/*
		 * @brief	Removes first element.
		 */
		void pop() {
			c.pop_back();
		}
	};

	/*
	 * @brief	Stack equality comparison.
	 * @param	lhs	A %stack.
	 * @param	rhs	A %stack of the same type as @a x.
	 * @return	True if the size and elements of the stacks are equal.
	 */
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c == rhs.c);
	}

	/*
	 * @brief	Stack ordering relation.
	 * @param	lhs	A %stack.
	 * @param	rhs	A %stack of the same type as @a lhs.
	 * @return	True if @a lhs is lexicographically less than @a rhs.
	 */
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