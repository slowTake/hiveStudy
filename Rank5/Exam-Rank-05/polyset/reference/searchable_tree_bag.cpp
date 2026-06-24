#include "searchable_tree_bag.hpp"

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

bool searchable_tree_bag::search(node *n, int value) {
	if (!n)
		return false;
	if (n->value == value)
		return true;
	if (value < n->value)
		return search(n->l, value);
	return search(n->r, value);
}

bool searchable_tree_bag::has(int value) const { return search(tree, value); }
