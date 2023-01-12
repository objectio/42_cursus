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
}

#endif