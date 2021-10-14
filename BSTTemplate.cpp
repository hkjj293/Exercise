#include "BST.h"
#include <iostream>

BST::BST() {
	root = NULL;
	depth = 0;
}

BST::~BST() {
	struct node* curr = this->root;
	struct node** stack = new node * [this->depth];
	for (int i = 0; i < this->depth; i++) {
		stack[i] = NULL;
	}
	int depth = 1;
	bool checkLeft = true;
	while (curr != NULL || depth != 1) {
		while (curr != NULL) {
			stack[depth - 1] = curr;
			depth++;
			curr = curr->left;
		}
		depth--;
		curr = stack[depth - 1];
		struct node* disposal = curr;
		curr = curr->right;
		std::cout << "deleting " << disposal->value << std::endl;
		delete disposal;
		disposal = NULL;
		std::cout << "deleted" << std::endl;
	}
	delete[] stack;
}

void BST::add_node(int val) {
	struct node** curr = &(this->root);
	int depth = 1;
	while ((*curr)!=NULL) {
		depth++;
		if (val < (*curr)->value) {
			curr = &((*curr)->left);
		}
		else {
			curr = &((*curr)->right);
		}
	}
	*curr = new node;
	(*curr)->left = NULL;
	(*curr)->right = NULL;
	(*curr)->value = val;
	this->depth += (this->depth < depth)*(depth - this->depth);
}

void BST::print() {
	struct node* curr = this->root;
	struct node** stack = new node* [this->depth];
	for (int i = 0; i < this->depth; i++) {
		stack[i] = NULL;
	}
	int depth = 1;
	bool checkLeft = true;
	while (curr != NULL || depth != 1) {
		while (curr != NULL) {
			stack[depth - 1] = curr;
			depth++;
			curr = curr->left;
		}
		depth--;
		curr = stack[depth - 1];
		std::cout << curr->value << std::endl;
		curr = curr->right;
	}
	delete[] stack;
}

bool BST::has_element(int val) {
	struct node* curr = this->root;
	while (curr != NULL) {
		if (val == curr->value) return true;
		if (val < curr->value) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return false;
}