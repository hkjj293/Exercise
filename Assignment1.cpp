#include <iostream>
#include <time.h>

void product(int a, int b);
double quotient(double a, int b);
void calculator(double a, double b, char op);
bool isNeg(int a);
void askTillNeg();
void swap(int* a, int* b);
void printEven(int* a);
int stackOverflow(int i);

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = NULL;

void insert_integer(struct node** tree, int value);
//void balanced_insert_integer(struct node** tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);
const int CELLNUM = 1000000;

int main()
{
	/*unsigned int a = -8;
	std::cout << a;
	std::cout << "Please Enter two numbers" << std::endl;
	int b,c;
	std::cin >> b;
	std::cin >> c;
	std::cout << c + b << std::endl << c * b;
	std::string name;
	std::cout << "Enter your name" << std::endl;
	std::cin >> name;
	std::cout << "Hello " << name << "!";*/
	product(12, 34);
	std::cout << quotient(5, 3) << std::endl;
	calculator(100, 3, '/');
	std::cout << isNeg(-23) << " " << isNeg(34) << std::endl;
	askTillNeg();
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
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };	printEven(arr);
	//stackOverflow(0);
	clock_t t;
	t = clock();
	//Method 1
	int* arr2 = new int[CELLNUM];
	for (int i = 0; i < CELLNUM; i++) { arr2[i] = i; }
	//for (int i = 0; i < 10; i++) { std::cout << arr2[i] << std::endl; }
	std::cout << "Method 1 :" << (clock() - t) << std::endl;
	delete[] arr2;

	//Method 2 --> use too much heap
	/*
	t = clock();
	int* arr3[CELLNUM];
	for (int i = 0; i < CELLNUM; i++) { arr3[i] = new int(i); }
	//for (int i = 0; i < 10; i++) { std::cout << arr3[i] << std::endl; }
	std::cout << "Method 2 :" << (clock() - t) << std::endl;
	for (int i = 0; i < CELLNUM; i++) { delete arr3[i]; }
	*/
	for (int i = 0; i < 20; i++) {
		insert_integer(&root, i * (-1 * (i % 2) + -1 * (i % 2 - 1)));
	}
	print_tree(root);
	terminate_tree(root);
	int a = 0;
	{int a = 0; }
	return 0;
}

void product(int a, int b) {
	std::cout << a * b << std::endl;
}

double quotient(double a, int b) {
	return a / b;
}

void calculator(double a, double b, char op) {
	switch (op){
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

void askTillNeg() {
	for (int a = 1; a >= 0;) {
		std::cout << "Please input an integer" << std::endl;
		std::cin >> a;
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printEven(int* a) {
	for (int i = 0; i < 10; i++) {
		if (*(a + i) % 2 == 0) { std::cout << *(a+i) << std::endl; }
	}
}

int stackOverflow(int i) {
	if (i == -1) return 1;
	return stackOverflow(i+1);
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

void terminate_tree(struct node* tree){
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
	else if (value < (*tree)->value){
		insert_integer(&((*tree)->left), value);
	}
	else{
		insert_integer(&((*tree)->right), value);
	}
}

