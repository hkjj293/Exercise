#pragma once
#include <string>

struct node {
	int value;
	struct node* left;
	struct node* right;
};

class BST {
public:
	BST();
	~BST();
	void add_node(int val);
	void print();
	bool has_element(int val);
private:
	struct node* root;
	int depth;
};
