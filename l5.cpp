#include "l5.h"
#include <iostream>
#include <string>

void print_tree(struct node* tree);
void terminate_tree(struct node*& tree);
void insert_integer(struct node** tree, int value);

struct node {
	int value;
	struct node* left;
	struct node* right;
};


l5::l5() {
	this->title = "===============  Lesson 5 ================ < Memory";
}

void l5::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
}

void l5::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "When stack memory is more than the limit. Recursive method occupies alot of stack whick one method holds memories when it calls it self until it recursive copy returns"<< std::endl;
}
void l5::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << "Heap. MUST delete all the memory on heap before quiting the program." << std::endl;
}

void l5::Q3() const {
	std::cout << "Q3:" << std::endl;
	char a = 'f';
	std::string* b = new std::string("Hi!");
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	delete b;
	b = NULL;
}

void l5::Q4() const {
	std::cout << "Q4:" << std::endl;
	int* arr2 = new int[10];
	for (int i = 0; i < 10; i++) { arr2[i] = i; }
	for (int i = 0; i < 10; i++) { std::cout << arr2[i] << std::endl; }
	delete[] arr2;
}

void l5::Q5() const {
	std::cout << "Q5:" << std::endl;
	struct node* root = NULL;
	srand(1);
	for (int i = 0; i < 2000; i++) {
		insert_integer(&root, rand()%80-40);
	}
	print_tree(root);
	terminate_tree(root);
}

void print_tree(struct node* tree) {
	if (tree->left != NULL) {
		print_tree(tree->left);
	}
	std::cout << tree->value << std::endl;
	if (tree->right != NULL) {
		print_tree(tree->right);
	}
}

void terminate_tree(struct node*& tree) {
	if (tree->left != NULL) {
		terminate_tree(tree->left);
	}
	if (tree->right != NULL) {
		terminate_tree(tree->right);
	}
	delete tree;
	tree = NULL;
}

void insert_integer(struct node** tree, int value) {
	if (*tree == NULL) {
		*tree = new node;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->value = value;
	}
	else if (value < (*tree)->value) {
		insert_integer(&((*tree)->left), value);
	}
	else {
		insert_integer(&((*tree)->right), value);
	}
}