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
		typedef Rb_tree_node<Val>*	Link_type;
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
		typedef T							value_type;
		typedef T&							reference;
		typedef T*							pointer;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t					difference_type;

		typedef Rb_tree_iterator<T>			Self;
		typedef Rb_tree_node_base::base_ptr	base_ptr;
		typedef Rb_tree_node<T>*			Link_type;
		base_ptr							node;

		Rb_tree_iterator() : node() { }

		explicit Rb_tree_iterator(Link_type x) : node(x) { }

		reference operator*() const {
			return (static_cast<Link_type>(node)->value_field);
		}

		pointer operator->() const {
			return (&static_cast<Link_type>(node)->value_field);
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
	};

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