#include "exercise.h"
#include <iostream>

void product(int a, int b);
double quotient(double a, int b);
void askTillNeg();
void calculator(double a, double b, char op);
bool isNeg(int a);
void swap(int* a, int* b);
void printEven(int* a);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);
void insert_integer(struct node** tree, int value);
void some_function();
void swap(int& a, int& b);
namespace p6 {
	void some_function();
}

void p1_hello_world() {
	unsigned int a = -8;
	std::cout << a;
	std::cout << "Please Enter two numbers" << std::endl;
	int b, c;
	std::cin >> b;
	std::cin >> c;
	std::cout << c + b << std::endl << c * b;
	std::string name;
	std::cout << "Enter your name" << std::endl;
	std::cin >> name;
	std::cout << "Hello " << name << "!";
}

void p2_functions() {
	product(12, 34);
	std::cout << quotient(5, 3) << std::endl;
}

void p3_program_flow() {
	calculator(100, 3, '/');
	std::cout << isNeg(-23) << " " << isNeg(34) << std::endl;
	askTillNeg();
}

void p4_pointers() {
	float floatVal = 100.0f;
	float* floatPtr = &floatVal;
	floatPtr = (float*)100;
	std::cout << (int)floatPtr << std::endl;
	floatPtr += 3;
	std::cout << (int)floatPtr << std::endl;
	//floatPtr += 3;
	int* ptrA = new int(90), * ptrB = new int(45);
	std::cout << *ptrA << " - " << *ptrB << std::endl;
	swap(ptrA, ptrB);
	std::cout << *ptrA << " - " << *ptrB << std::endl;
	delete ptrA;
	delete ptrB;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printEven(arr);
}

void p5_memory() {
	struct node* root = NULL;
	const int CELLNUM = 1000000;

	//Method 1 --> craate a pointer to an array of size CELLNUM in stack (size 1 QWORD)
	int* arr2 = new int[CELLNUM];
	for (int i = 0; i < CELLNUM; i++) { arr2[i] = i; }
	//for (int i = 0; i < 10; i++) { std::cout << arr2[i] << std::endl; }
	delete[] arr2;

	//Method 2 --> use too much stack coz it create an array of size CELLNUM in stack (size CELLNUM QWORD)
	/*
	t = clock();
	int* arr3[CELLNUM];
	for (int i = 0; i < CELLNUM; i++) { arr3[i] = new int(i); }
	//for (int i = 0; i < 10; i++) { std::cout << arr3[i] << std::endl; }
	for (int i = 0; i < CELLNUM; i++) { delete arr3[i]; }
	*/
	for (int i = 0; i < 20; i++) {
		insert_integer(&root, i * (-1 * (i % 2) + -1 * (i % 2 - 1)));
	}
	print_tree(root);
	terminate_tree(root);
}

void p6_scope_and_extent() {
	int a = 2;
	int b = 3;
	{int a = 0; }
	some_function();
	p6::some_function();
}

void p7_reference() {
	int a = 89;
	int b = 64;
	std::cout << a << "-" << b << std::endl;
	swap(a, b);
	std::cout << a << "-" << b << std::endl;
}

void product(int a, int b) {
	std::cout << a * b << std::endl;
}

double quotient(double a, int b) {
	return a / b;
}

void askTillNeg() {
	for (int a = 1; a >= 0;) {
		std::cout << "Please input an integer" << std::endl;
		std::cin >> a;
	}
}

void calculator(double a, double b, char op) {
	switch (op) {
	case '+':
		std::cout << a + b << std::endl;
		break;
	case '-':
		std::cout << a - b << std::endl;
		break;
	case '*':
		std::cout << a * b << std::endl;
		break;
	case '/':
		std::cout << a / b << std::endl;
		break;
	default:
		std::cout << "Invalid operator" << std::endl;
	}
}

bool isNeg(int a) {
	return a >= 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printEven(int* a) {
	for (int i = 0; i < 10; i++) {
		if (*(a + i) % 2 == 0) { std::cout << *(a + i) << std::endl; }
	}
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

void terminate_tree(struct node* tree) {
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

void some_function() {
	std::cout << "some function outside p6" << std::endl;
}


void p6::some_function() {
	std::cout << "some function inside p6" << std::endl;
}



void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}