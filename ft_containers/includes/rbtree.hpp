#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "containers.hpp"

namespace ft {
	enum Rb_tree_color { red = false, black = true };

	struct Rb_tree_node_base {
		typedef Rb_tree_node_base*			base_ptr;
		typedef typename Rb_tree_node_base*	const_base_ptr;

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
		typedef Rb_tree_node<Val>*	type;
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

	Rb_tree_node_base* Rb_tree_rebalance_for_erase(Rb_tree_node_base* const z, Rb_tree_node_base& header);
}

#endif