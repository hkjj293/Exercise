#include "ComparableBST.h"
#include <iostream>

ComparableBST::ComparableBST() {
	root = NULL;
	depth = 0;
}

ComparableBST::~ComparableBST() {
	struct Comparablenode* curr = this->root;
	struct Comparablenode** stack = new Comparablenode * [this->depth];
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
		struct Comparablenode* disposal = curr;
		curr = curr->right;
		std::cout << "deleting " << disposal->value->toString() << std::endl;
		if (disposal->value != NULL) {
			delete disposal->value;
			disposal->value = NULL;
		}
		delete disposal;
		disposal = NULL;
		std::cout << "deleted" << std::endl;
	}
	delete[] stack;
}

void ComparableBST::add_node(Comparable* value) {
	struct Comparablenode** curr = &(this->root);
	int depth = 1;
	while ((*curr)!=NULL) {
		depth++;
		if ((*curr)->value->compare_to(*value)>0) {
			curr = &((*curr)->left);
		}
		else {
			curr = &((*curr)->right);
		}
	}
	*curr = new Comparablenode;
	(*curr)->left = NULL;
	(*curr)->right = NULL;
	(*curr)->value = value;
	this->depth += (this->depth < depth)*(depth - this->depth);
}

void ComparableBST::print() {
	struct Comparablenode* curr = this->root;
	struct Comparablenode** stack = new Comparablenode * [this->depth];
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
		std::cout << curr->value->toString() << std::endl;
		curr = curr->right;
	}
	delete[] stack;
}

bool ComparableBST::has_element(Comparable& value) {
	struct Comparablenode* curr = this->root;
	while (curr != NULL) {
		if (value.compare_to(*((*curr).value)) == 0) return true;
		if (curr->value->compare_to(value) < 0) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return false;
}