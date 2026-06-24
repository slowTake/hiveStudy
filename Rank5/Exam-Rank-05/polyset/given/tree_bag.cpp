#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() : tree(nullptr) {}

tree_bag::tree_bag(const tree_bag &src) : tree(copy_node(src.tree)) {}

tree_bag::~tree_bag() { destroy_tree(tree); }

tree_bag &tree_bag::operator=(const tree_bag &src) {
	if (this != &src) {
		destroy_tree(tree);
		tree = copy_node(src.tree);
	}
	return *this;
}

tree_bag::node *tree_bag::extract_tree() {
	node *tmp = tree;
	tree = nullptr;
	return tmp;
}

void tree_bag::set_tree(node *new_tree) {
	destroy_tree(tree);
	tree = new_tree;
}

void tree_bag::insert(int item) {
	node *new_node = new node;
	new_node->value = item;
	new_node->l = nullptr;
	new_node->r = nullptr;

	if (!tree) {
		tree = new_node;
		return;
	}

	node *cur = tree;
	while (true) {
		if (item < cur->value) {
			if (!cur->l) {
				cur->l = new_node;
				return;
			}
			cur = cur->l;
		} else if (item > cur->value) {
			if (!cur->r) {
				cur->r = new_node;
				return;
			}
			cur = cur->r;
		} else {
			delete new_node;
			return;
		}
	}
}

void tree_bag::insert(int *items, int count) {
	for (int i = 0; i < count; ++i)
		insert(items[i]);
}

void tree_bag::print() const {
	print_node(tree);
	std::cout << std::endl;
}

void tree_bag::clear() {
	destroy_tree(tree);
	tree = nullptr;
}

void tree_bag::destroy_tree(node *cur) {
	if (!cur)
		return;
	destroy_tree(cur->l);
	destroy_tree(cur->r);
	delete cur;
}

void tree_bag::print_node(node *cur) {
	if (!cur)
		return;
	print_node(cur->l);
	if (cur->value != 0)
		std::cout << cur->value << " ";
	print_node(cur->r);
}

tree_bag::node *tree_bag::copy_node(node *cur) {
	if (!cur)
		return nullptr;
	node *n = new node;
	n->value = cur->value;
	n->l = copy_node(cur->l);
	n->r = copy_node(cur->r);
	return n;
}
