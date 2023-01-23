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
		Rep_type	m_t;    // 실질적 tree

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

		/*
		 * @breif	Default constructor creates no elements.
		 */
		map()
		: m_t(Compare(), allocator_type()) { }

		explicit map(const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) { }

		/*
		 * @breif	Map copy constructor.
		 * @param	x,	A %map of identical element and allocator types.
		 * 
		 * The newly-created %map uses a copy of the allocation object used by @a x.
		 */
		map(const map& x)
		: m_t(x.m_t) { }

		/*
		 * @breif	Builds a %map from a range.
		 * @param	first,	An input iterator.
		 * @param	last,	An input iterator.
		 * 
		 * Create a %map consisting of copies of the elements from [first,last).
		 * This is linear in N if the range is already sorted, and NlogN otherwise (where N is distance(first,last)).
		 */
		template <typename InputIterator>
		map(InputIterator first, InputIterator last)
		: m_t(Compare(), allocator_type()) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @breif	Builds a %map from a range.
		 * @param	first,	An input iterator.
		 * @param	last,	An input iterator.
		 * @param	comp,	A comparison functor.
		 * @param	a,		An allocator object.
		 * 
		 * Create a %map consisting of copies of the elements from [first,last).
		 * This is linear in N if the range is already sorted, and NlogN otherwise (where N is distance(first,last)).
		 */
		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, a) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @breif	Map assignment operator.
		 * @param	x, A %map of identical element and allocator types.
		 * 
		 * All the elements of @a x are copied, but unlike the copy constructor, the allocator object is not copied.
		 */
		map& operator=(const map& x) {
			m_t = x.m_t;
			return (*this);
		}

		// Get a copy of the memory allocation object.
		allocator_type get_allocator() const {
			return m_t.get_allocator();
		}

		// Returns a read/write iterator that points to the first pair in the @map.
		// Iteration is done in ascending order(오름차순) according to the keys.
		iterator begin() {
			return (m_t.begin());
		}

		// read-only iterator
		const_iterator begin() const {
			return (m_t.begin());
		}

		// Returns a read/write iterator that points one past the last pair in the %map.
		// Iteration is done in ascending order according to the keys.
		iterator end() {
			return (m_t.end());
		}

		const_iterator end() const {
			return (m_t.end());
		}

		// Returns a read/write reverse iterator that points to the last pair in the %map.
		// Iteration is done in descending order according to the keys.
		reverse_iterator rbegin() {
			return (m_t.rbegin());
		}

		const_reverse_iterator rbegin() const {
			return (m_t.rbegin());
		}

		// Returns a read/write reverse iterator that points to one before the first pair in the %map.
		// Iteration is done in descending order according to the keys.
		reverse_iterator rend() {
			return (m_t.rend());
		}

		const_reverse_iterator rend() const {
			return (m_t.rend());
		}

		// Returns true if the %map is empty. (Thus begin() would equal end().)
		bool empty() const {
			return (m_t.empty());
		}

		// Returns the size of the %map.
		size_type size() const {
			return (m_t.size());
		}

		// Returns the maximum size of the %map.
		size_type max_size() const {
			return (m_t.max_size());
		}

		/*
		 * @breif	element accessor to %map data.
		 * @param	k,	검색하고 싶은 값의 key
		 * @return	A reference to the data of the (key,data) %pair.
		 */
		mapped_type& operator[](const key_type& k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return ((*i).second);
		}

		/*
		 * @breif	Access to %map data.
		 * @param	k,	검색하고 싶은 값의 key
		 * @return	A reference to the data whose key is equivalent to @a k, if such a data is present in the %map.
		 * @throw	std::out_of_range  If no such data is present.
		 */
		mapped_type& at(const key_type& k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::range_error("ft::map::at");
			return ((*i).second);
		}

		const mapped_type& at(const key_type& k) const {
			const_iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::range_error("ft::map::at");
			return ((*i).second);
		}

		/*
		 * @breif	Attempts to insert a ft::pair into the %map.
		 * @param	x,	Pair to be inserted.
		 * @return	first 요소로 inserted pair를 가리키는 iterator, 
		 * 			second 요소로 pair의 inserted 여부를 알려주는 bool을 가지는 pair.
		 */
		ft::pair<iterator, bool> insert(const value_type& x) {
			return (m_t.insert_unique(x));
		}

		/*
		 * @breif	Attempts to insert a ft::pair into the %map.
		 * @param	position,	user가 insert를 최적화시킬 수 있는 위치(hint)를 인자로 넘겨줌.
		 * @param	x,	Pair to be inserted.
		 * @return	x의 키가 들어있는 요소를 가리키는 iterator. 
		 */
		iterator insert(iterator position, const value_type& x) {
			return (m_t.insert_unique(position, x));
		}

		/*
		 * @breif	Template function that attemps to insert a range of elements.
		 * @param	first,	Iterator pointing to the start of the range to be inserted.
		 * @param	last,	Iterator pointing to the end of the range.
		 * @return	x의 키가 들어있는 요소를 가리키는 iterator. 
		 */
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			m_t.insert_unique(first, last);
		}

		/*
		 * @brief	Erases an element from a %map.
		 * @param	position,	An iterator pointing to the element to be erased.
		 */
		void erase(iterator position) {
			m_t.erase(position);
		}

		/*
		 * @brief	Erases elements according to the provided key.
		 * @param	x,	Key of element to be erased.
		 * @return	The number of elements erased.
		 */
		size_type erase(const key_type& x) {
			return (m_t.erase(x));
		}

		void erase(iterator first, iterator last) {
			m_t.erase(first, last);
		}

		void swap(map& x) {
			m_t.swap(x.m_t);
		}

		void clear() {
			m_t.clear();
		}

		key_compare key_comp() const {
			return (m_t.key_comp());
		}

		value_compare value_comp() const {
			return (value_compare(m_t.key_comp()));
		}

		iterator find(const key_type& x) {
			return (m_t.find(x));
		}

		const_iterator find(const key_type& x) const {
			return (m_t.find(x));
		}

		size_type count(const key_type& x) const {
			return (m_t.find(x) == m_t.end() ? 0 : 1);
		}

		iterator lower_bound(const key_type& x) {
			return (m_t.lower_bound(x));
		}

		const_iterator lower_bound(const key_type& x) const {
			return (m_t.lower_bound(x));
		}

		iterator upper_bound(const key_type& x) {
			return (m_t.upper_bound(x));
		}

		const_iterator upper_bound(const key_type& x) const {
			return (m_t.upper_bound(x));
		}

		ft::pair<iterator, iterator> equal_range(const key_type& x) {
			return (m_t.equal_range(x));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type& x) const {
			return (m_t.equal_range(x));
		}

		template <typename _Key, typename _T, typename _Compare, typename _Allocator>
		friend bool operator==(const map<_Key, _T, _Compare, _Allocator>&, const map<_Key, _T, _Compare, _Allocator>&);

		template <typename _Key, typename _T, typename _Compare, typename _Allocator>
		friend bool operator<(const map<_Key, _T, _Compare, _Allocator>&, const map<_Key, _T, _Compare, _Allocator>&);
	};

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (x.m_t == y.m_t);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (x.m_t < y.m_t);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x == y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return (y < x);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(y < x);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x < y);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y) {
		x.swap(y);
	}
}

#endif