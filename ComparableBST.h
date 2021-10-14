#pragma once
#include <string>
#include "Comparable.h"

struct Comparablenode {
	Comparable* value;
	struct Comparablenode* left;
	struct Comparablenode* right;
};

class ComparableBST {
public:
	ComparableBST();
	~ComparableBST();
	void add_node(Comparable* value);
	void print();
	bool has_element(Comparable& value);
private:
	struct Comparablenode* root;
	int depth;
};
