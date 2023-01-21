#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "containers.hpp"

namespace ft {
	enum Rb_tree_color { red = false, black = true };

	struct Rb_tree_node_base {
		typedef Rb_tree_node_base*			base_ptr;
		typedef const Rb_tree_node_base*	const_base_ptr;

		Rb_tree_color	color;
		base_ptr		parent;
		base_ptr		left;
		base_ptr		right;

		static base_ptr minimum (base_ptr x) {
			while (x->left != 0)
				x = x->left;
			return (x);
		}

		static const_base_ptr minimum (const_base_ptr x) {
			while (x->left != 0)
				x = x->left;
			return (x);
		}

		static base_ptr maximum (base_ptr x) {
			while (x->right != 0)
				x = x->right;
			return (x);
		}

		static const_base_ptr maximum (const_base_ptr x) {
			while (x->right != 0)
				x = x->right;
			return (x);
		}
	};

	template <typename Val>
	struct Rb_tree_node : public Rb_tree_node_base {
		typedef Rb_tree_node<Val>*	link_type;
		Val							value_field;
	};

	Rb_tree_node_base* Rb_tree_increment (Rb_tree_node_base* x) {
		if (x->right != 0) {
			x = x->right;
			while (x->left != 0)
				x = x->left;
		}
		else {
			Rb_tree_node_base* y = x->parent;
			while (x == y->right) {
				x = y;
				y = y->parent;
			}
			if (x->right != y)
				x = y;
		}
		return (x);
	}

	const Rb_tree_node_base* Rb_tree_increment (const Rb_tree_node_base* x) {
		return (Rb_tree_increment(const_cast<Rb_tree_node_base*>(x)));
	}

	Rb_tree_node_base* Rb_tree_decrement(Rb_tree_node_base* x) {
		if (x->color == red && x->parent->parent == x)
			x = x->right;
		else if (x->left != 0) {
			Rb_tree_node_base* y = x->left;
			while (y->right != 0)
				y = y->right;
			x = y;
		}
		else {
			Rb_tree_node_base* y = x->parent;
			while (x == y->left) {
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return (x);
	}

	const Rb_tree_node_base* Rb_tree_decrement(const Rb_tree_node_base* x) {
		return (Rb_tree_decrement(const_cast<Rb_tree_node_base*>(x)));
	}

	template <typename T>
	struct Rb_tree_iterator {
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;

		typedef Rb_tree_iterator<T>				Self;
		typedef Rb_tree_node_base::base_ptr		base_ptr;
		typedef Rb_tree_node<T>*				link_type;
		base_ptr								node;

		Rb_tree_iterator() : node() { }

		explicit Rb_tree_iterator(link_type x) : node(x) { }

		reference operator*() const {
			return (static_cast<link_type>(node)->value_field);
		}

		pointer operator->() const {
			return (&static_cast<link_type>(node)->value_field);
		}

		Self& operator++() {
			node = Rb_tree_increment(node);
			return (*this);
		}

		Self operator++(int) {
			Self tmp = *this;
			node = Rb_tree_increment(node);
			return (tmp);
		}

		Self& operator--() {
			node = Rb_tree_decrement(node);
			return (*this);
		}

		Self operator--(int) {
			Self tmp = *this;
			node = Rb_tree_decrement(node);
			return (tmp);
		}

		bool operator==(const Self& x) const {
			return (node == x.node);
		}

		bool operator!= (const Self& x) const {
			return (node != x.node);
		}
	};

	template <typename T>
	struct Rb_tree_const_iterator {
		typedef T			value_type;
		typedef const T&	reference;
		typedef const T*	pointer;

		typedef Rb_tree_iterator<T>					iterator;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef ptrdiff_t							difference_type;

		typedef Rb_tree_const_iterator<T>			Self;
		typedef Rb_tree_node_base::const_base_ptr	base_ptr;
		typedef const Rb_tree_node<T>*				link_type;
		base_ptr									node;

		Rb_tree_const_iterator() : node() { }

		explicit Rb_tree_const_iterator(link_type x) : node(x) { }

		Rb_tree_const_iterator(const iterator& it) : node(it.node) { }

		reference operator*() const {
			return (static_cast<link_type>(node)->value_field);
		}

		pointer operator->() const {
			return (&static_cast<link_type>(node)->value_field);
		}

		Self& operator++() {
			node = Rb_tree_increment(node);
			return (*this);
		}

		Self operator++(int) {
			Self tmp = *this;
			node = Rb_tree_increment(node);
			return (tmp);
		}

		Self& operator--() {
			node = Rb_tree_decrement(node);
			return (*this);
		}

		Self operator--(int) {
			Self tmp = *this;
			node = Rb_tree_decrement(node);
			return (tmp);
		}

		bool operator==(const Self& x) const {
			return (node == x.node);
		}

		bool operator!=(const Self& x) const {
			return (node != x.node);
		}
	};

	template <typename Val>
	bool operator==(const Rb_tree_iterator<Val>& x, const Rb_tree_const_iterator<Val>& y) {
		return (x.node == y.node);
	}

	template <typename Val>
	bool operator!=(const Rb_tree_iterator<Val>& x, const Rb_tree_const_iterator<Val>& y) {
		return (x.node != y.node);
	}

	void Rb_tree_rotate_left(Rb_tree_node_base* const x, Rb_tree_node_base*& root) {
		Rb_tree_node_base* const y = x->right;

		x->right = y->left;
		if (y->left != 0)
			y->left->parent = x;
		y->parent = x->parent;

		if (x == root)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void Rb_tree_rotate_right(Rb_tree_node_base* const x, Rb_tree_node_base*& root) {
		Rb_tree_node_base* const y = x->left;

		x->left = y->right;
		if (y->right != 0)
			y->right->parent = x;
		y->parent = x->parent;

		if (x == root)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void Rb_tree_insert_and_rebalance(const bool insert_left, Rb_tree_node_base* x, Rb_tree_node_base* p, Rb_tree_node_base& header) {
		Rb_tree_node_base *& root = header.parent;

		// initialize fileds in new node to insert
		x->parent = p;
		x->left = 0;
		x->right = 0;
		x->color = red;

		// insert
		if (insert_left) {
			p->left = x;

			if (p == &header) {
				header.parent = x;
				header.right = x;
			}
			else if (p == header.left)
				header.left = x;
		}
		else {
			p->right = x;

			if (p == header.right)
				header.right = x;
		}

		// rebalance
		while (x != root && x->parent->color == red) {
			Rb_tree_node_base* const xpp = x->parent->parent;

			if (x->parent == xpp->left) {
				Rb_tree_node_base* const y = xpp->right;
				if (y && y->color == red) {
					x->parent->color = black;
					y->color = black;
					xpp->color = red;
					x = xpp;
				}
				else {
					if (x == x->parent->right) {
						x = x->parent;
						Rb_tree_rotate_left(x, root);
					}
					x->parent->color = black;
					xpp->color = red;
					Rb_tree_rotate_right(xpp, root);
				}
			}
			else {
				Rb_tree_node_base* const y = xpp->left;
				if (y && y->color == red) {
					x->parent->color = black;
					y->color = black;
					xpp->color = red;
					x = xpp;
				}
				else {
					if (x == x->parent->left) {
						x = x->parent;
						Rb_tree_rotate_right(x, root);
					}
					x->parent->color = black;
					xpp->color = red;
					Rb_tree_rotate_left(xpp, root);
				}
			}
		}
		root->color = black;
	}

	Rb_tree_node_base* Rb_tree_rebalance_for_erase(Rb_tree_node_base* const z, Rb_tree_node_base& header) {
		Rb_tree_node_base *& root = header.parent;
		Rb_tree_node_base *& left = header.left;
		Rb_tree_node_base *& right = header.right;
		Rb_tree_node_base* y = z;
		Rb_tree_node_base* x = 0;
		Rb_tree_node_base* x_parent = 0;

		if (y->left == 0)
			x = y->right;
		else {
			if (y->right == 0)
				x = y->left;
			else {
				y = y->right;
				while (y->left != 0)
					y = y->left;
				x = y->right;
			}
		}

		if (y != z) {
			z->left->parent = y;
			y->left = z->left;
			if (y != z->right) {
				x_parent = y->parent;
				if (x) x->parent = y->parent;
				y->parent->left = x;
				y->right = z->right;
				z->right->parent = y;
			}
			else
				x_parent = y;
			
			if (root == z)
				root = y;
			else if (z->parent->left == z)
				z->parent->left = y;
			else
				z->parent->right = y;
			y->parent = z->parent;
			//swap
			Rb_tree_color tmp = y->color;
			y->color = z->color;
			z->color = tmp;
			y = z;
		}
		else {
			x_parent = y->parent;
			if (x)
				x->parent = y->parent;
			if (root == z)
				root = x;
			else
				if (z->parent->left == z)
					z->parent->left = x;
				else
					z->parent->right = x;
			
			if (left == z) {
				if (z->right == 0)
					left = z->parent;
				else
					left = Rb_tree_node_base::minimum(x);
			}
			if (right == z) {
				if (z->left == 0)
					right = z->parent;
				else
					right = Rb_tree_node_base::maximum(x);
			}
		}

		if (y->color != red) {
			while (x != root && (x == 0 || x->color == black)) {
				if (x == x_parent->left) {
					Rb_tree_node_base* w = x_parent->right;
					if (w->color == red) {
						w->color = black;
						x_parent->color = red;
						Rb_tree_rotate_left(x_parent, root);
						w = x_parent->right;
					}
					if ((w->left == 0 || w->left->color == black) && (w->right == 0 || w->right->color == black)) {
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else {
						if (w->right == 0 || w->right->color == black) {
							w->left->color = black;
							w->color = red;
							Rb_tree_rotate_right(w, root);
							w = x_parent->right;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->right)
							w->right->color = black;
						Rb_tree_rotate_left(x_parent, root);
						break;
					}
				}
				else {
					Rb_tree_node_base* w = x_parent->left;
					if (w->color == red) {
						w->color = black;
						x_parent->color = red;
						Rb_tree_rotate_right(x_parent, root);
						w = x_parent->left;
					}
					if ((w->right == 0 || w->right->color == black) && (w->left == 0 || w->left->color == black)) {
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else {
						if (w->left == 0 || w->left->color == black) {
							w->right->color = black;
							w->color = red;
							Rb_tree_rotate_left(w, root);
							w = x_parent->left;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->left)
							w->left->color = black;
						Rb_tree_rotate_right(x_parent, root);
						break;
					}
				}
			}
			if (x) x->color = black; // OB
		}
		return (y);
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
	class Rb_tree {
		typedef typename Alloc::template rebind<Rb_tree_node<Val> >::other Node_allocator;

		protected:
		typedef Rb_tree_node_base*			base_ptr;
		typedef const Rb_tree_node_base*	const_base_ptr;
		typedef Rb_tree_node<Val>			Rb_tree_node;

		public:
		typedef Key							key_type;
		typedef Val							value_type;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef Rb_tree_node*				link_type;
		typedef const Rb_tree_node*			const_link_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Alloc						allocator_type;

		/* MEMBER VARIABLE */
		Compare								key_compare;
		Rb_tree_node_base					header;
		size_type							node_count;

		Node_allocator& get_Node_allocator() {
			return (*static_cast<Node_allocator*>(&this));
		}

		const Node_allocator& get_Node_allocator() const {
			return (*static_cast<const Node_allocator*>(&this));
		}

		allocator_type get_allocator() const {
			return (allocator_type(get_Node_allocator()));
		}

		protected:
		Rb_tree_node* get_node() {
			return (Node_allocator::allocate(1));
		}

		void put_node(Rb_tree_node* p) {
			Node_allocator::deallocate(p, 1);
		}

		link_type create_node(const value_type& x) { // OB
			link_type tmp = get_node();
			get_allocator().construct(&tmp->value_field, x);
			put_node(tmp);
			return (tmp);
		}

		link_type clone_node(const_link_type x) {
			link_type tmp = create_node(x->value_field);
			tmp->color = x->color;
			tmp->left = 0;
			tmp->right = 0;
			return (tmp);
		}

		void destroy_node(link_type p) {
			get_allocator().destroy(&p->value_field);
			put_node(p);
		}

		base_ptr& root() {
			return (this->header.parent);
		}

		const_base_ptr root() const {
			return (this->header.parent);
		}

		base_ptr& leftmost() {
			return (this->header.left);
		}

		const_base_ptr leftmost() const {
			return (this->header.left);
		}

		base_ptr& rightmost() {
			return (this->header.right);
		}

		const_base_ptr rightmost() const {
			return (this->header.right);
		}

		link_type m_begin() {
			return (static_cast<link_type>(this->header.parent));
		}

		const_link_type m_begin() const {
			return (static_cast<const_link_type>(this->header.parent));
		}

		link_type m_end() {
			return (static_cast<link_type>(&this->header));
		}

		const_link_type m_end() const {
			return (static_cast<const_link_type>(&this->header));
		}

		static const_reference value(const_link_type x) {
			return (x->value_field);
		}

		static const Key& key(const_link_type x) {
			return (KeyOfValue()(value(x)));
		}

		static link_type left(base_ptr x) {
			return (static_cast<link_type>(x->left));
		}

		static const_link_type left(const_base_ptr x) {
			return (static_cast<const_link_type>(x->left));
		}

		static link_type right(base_ptr x) {
			return (static_cast<link_type>(x->right));
		}

		static const_link_type right(const_base_ptr x) {
			return (static_cast<const_link_type>(x->right));
		}

		static const_reference value(const_base_ptr x) {
			return (static_cast<const_link_type>(x)->value_field);
		}

		static const Key& key(const_base_ptr x) {
			return (KeyOfValue()(value(x)));
		}

		static base_ptr minimum(base_ptr x) {
			return (Rb_tree_node_base::minimum(x));
		}

		static const_base_ptr minimum(const_base_ptr x) {
			return (Rb_tree_node_base::minimum(x));
		}

		static base_ptr maximum(base_ptr x) {
			return (Rb_tree_node_base::maximum(x));
		}

		static const_base_ptr maximum(const_base_ptr x) {
			return (Rb_tree_node_base::maximum(x));
		}

		public:
		typedef Rb_tree_iterator<value_type>			iterator;
		typedef Rb_tree_const_iterator<value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
		iterator insert(base_ptr x, base_ptr y, const value_type& v) {
			bool insert_left = (x != 0 || y == m_end() || key_compare(KeyOfValue()(v), key(y)));
			link_type z = create_node(v);

			Rb_tree_insert_and_rebalance(insert_left, z, y, this->header);
			++node_count;
			return (iterator(z));
		}

		iterator insert_lower(base_ptr x, base_ptr y, const value_type& v) {
			bool insert_left = (x != 0 || y == m_end() || !key_compare(key(y), KeyOfValue()(v)));
			link_type z = create_node(v);

			Rb_tree_insert_and_rebalance(insert_left, z, y, this->header);
			++node_count;
			return (iterator(z));
		}

		const_iterator insert(const_base_ptr x, const_base_ptr y, const value_type& v) {
			bool insert_left = (x != 0 || y == m_end() || key_compare(KeyOfValue()(v), key(y)));
			link_type z = create_node(v);

			Rb_tree_insert_and_rebalance(insert_left, z, const_cast<base_ptr>(y), this->header);
			++node_count;
			return (const_iterator(z));
		}

		link_type copy(const_link_type x, link_type p);  // TODO

		void erase(link_type x) {
			while (x != 0) {
				erase(right(x));
				link_type y = left(x);
				destroy_node(x);
				x = y;
			}
		}

		public:
		Rb_tree() { }

		Rb_tree(const Compare& comp) : Node_allocator(allocator_type()), key_compare(comp), header(), node_count(0) {
			this->header.color = red;
			this->header.parent = 0;
			this->header.left = &this->header;
			this->header.right = &this->header;
		}

		Rb_tree(const Compare& comp, const allocator_type& a)
		: Node_allocator(a), key_compare(comp), header(), node_count(0) {
			this->header.color = red;
			this->header.parent = 0;
			this->header.left = &this->header;
			this->header.right = &this->header;
		}

		Rb_tree(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x)
		: Node_allocator(x.get_Node_allocator()), key_compare(x.key_compare), header(), node_count(x.node_count) {
			this->header.color = red;
			this->header.parent = 0;
			this->header.left = &this->header;
			this->header.right = &this->header;

			if (x.root() != 0) {
				root() = copy(x.m_begin(), m_end());
				leftmost() = minimum(root());
				rightmost() = maximum(root());
			}
		}

		~Rb_tree() {
			erase(m_begin());
		}

		Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& operator=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x) {
			if (this != &x) {
				clear();
				this->key_compare = x.key_compare;
				if (x.root() != 0) {
					root() = copy(x.m_begin(), m_end());
					leftmost() = minimum(root());
					rightmost() = maximum(root());
					node_count = x.node_count;
				}
			}
			return (*this);
		}

		/* ACCESSORS */
		Compare key_comp() const {
			return (key_compare);
		}

		iterator begin() {
			return (iterator(static_cast<link_type>(this->header.left)));
		}

		const_iterator begin() const {
			return (const_iterator(static_cast<const_link_type>(this->header.left)));
		}

		iterator end() {
			return (iterator(static_cast<link_type>(&this->header)));
		}

		const_iterator end() const {
			return (const_iterator(static_cast<const_link_type>(&this->header)));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

		bool empty() const {
			return (node_count == 0);
		}

		size_type size() const {
			return (node_count);
		}

		size_type max_size() const {
			return (get_allocator().max_size());
		}

		void swap(Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& t); // TODO

		// TODO : insert_equal or insert_unique ?

		void erase(iterator position) {
			link_type y = static_cast<link_type>(Rb_tree_rebalance_for_erase(position.node, this->header));
			destroy_node(y);
			--node_count;
		}

		void erase(const_iterator position) {
			link_type y = static_cast<link_type>(Rb_tree_rebalance_for_erase(const_cast<base_ptr>(position.node), this->header));
			destroy_node(y);
			--node_count;
		}

		size_type erase(const key_type& x) {
			pair<iterator,iterator> p = equal_range(x);
			const size_type old_size = size();
			erase(p.first, p.second);
			return (old_size - size());
		}

		void erase(iterator first, iterator last) {
			if (first == begin() && last == end())	clear();
			else {
				while (first != last)
					erase(first++);
			}
		}

		void erase(const_iterator first, const_iterator last) {
			if (first == begin() && last == end())	clear();
			else {
				while (first != last)
					erase(first++);
			}
		}

		void erase(const key_type* first, const key_type* last) {
			while (first != last)	erase(*first++);
		}

		void clear() {
			erase(m_begin());
			leftmost() = m_end();
			root() = 0;
			rightmost() = m_end();
			node_count = 0;
		}

		// Set operations
		iterator find(const key_type& k) {
			link_type x = m_begin();
			link_type y = m_end();

			while (x != 0) {
				if (!key_compare(key(x), k)) {
					y = x;
					x = left(x);
				}
				else 
					x = right(x);
			}

			iterator i = iterator(y);
			return ((i == end() || key_compare(k, key(i.node))) ? end() : i);
		}

		const_iterator find(const key_type& k) const  {
			const_link_type x = m_begin();
			const_link_type y = m_end();

			while (x != 0) {
				if (!key_compare(key(x), k)) {
					y = x;
					x = left(x);
				}
				else 
					x = right(x);
			}

			const_iterator i = const_iterator(y);
			return ((i == end() || key_compare(k, key(i.node))) ? end() : i);
		}

		size_type count(const key_type& k) const {
			pair<const_iterator, const_iterator> p = equal_range(k);
			const size_type n = ft::distance(p.first, p.second);
			return (n);
		}

		iterator lower_bound(const key_type& k) {
			link_type x = m_begin();
			link_type y = m_end();

			while (x != 0) {
				if (!key_compare(key(x), k)) {
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			}
			return (iterator(y));
		}

		const_iterator lower_bound(const key_type& k) const {
			const_link_type x = m_begin();
			const_link_type y = m_end();

			while (x != 0) {
				if (!key_compare(key(x), k)) {
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			}
			return (const_iterator(y));
		}

		iterator upper_bound(const key_type& k) {
			link_type x = m_begin();
			link_type y = m_end();

			while (x != 0) {
				if (key_compare(k, key(x))) {
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			}
			return (iterator(y));
		}

		const_iterator upper_bound(const key_type& k) const {
			const_link_type x = m_begin();
			const_link_type y = m_end();

			while (x != 0) {
				if (key_compare(k, key(x))) {
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			}
			return (const_iterator(y));
		}

		pair<iterator,iterator> equal_range(const key_type& x) {
			return (pair<iterator,iterator>(lower_bound(x), upper_bound(x)));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type& x) const {
			return (pair<const_iterator,const_iterator>(lower_bound(x), upper_bound(x)));
		}

		bool rb_verify() const {
			if (node_count == 0 || begin() == end())
				return (node_count == 0 && begin() == end()
				&& this->header.left == m_end()
				&& this->header.right == m_end());

			unsigned int len = Rb_tree_black_count(leftmost(), root());
			for (const_iterator it = begin(); it != end(); ++it) {
				const_link_type x = static_cast<const_link_type>(it.node);
				const_link_type L = left(x);
				const_link_type R = right(x);

				if (x->color == red)
					if ((L && L->color == red) || (R && R->color == red))
						return (false);

				if (L && key_compare(key(x), key(L)))
					return (false);

				if (R && key_compare(key(R), key(x)))
					return (false);

				if (!L && !R && Rb_tree_black_count(x, root()) != len)
					return (false);
			}

			if (leftmost() != Rb_tree_node_base::minimum(root()))
				return (false);
			
			if (rightmost() != Rb_tree_node_base::maximum(root()))
				return (false);

			return (true);
		}
	};

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator==(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator<(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator!=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return !(x == y);
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator>(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return (y < x);
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator<=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return !(y < x);
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator>=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		return !(x < y);
	}

	template <typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
	void swap(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x, const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y) {
		x.swap(y);
	}

	unsigned int Rb_tree_black_count(const Rb_tree_node_base* node, const Rb_tree_node_base* root) {
		if (node == 0)
			return 0;
		unsigned int sum = 0;
		do {
			if (node->color == black)
				++sum;
			if (node == root)
				break;
			node = node->parent;
		} while (1);
		return (sum);
	}
}

#endif