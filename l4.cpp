#include "l4.h"
#include <iostream>

void swap(int* a, int* b);
void printEven(int* a);

l4::l4() {
	this->title = "===============  Lesson 4 ================ < Pointers:";
}

void l4::ans() const {
	std::cout << this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
}

void l4::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "memory addresses are interger" << std::endl;
}
void l4::Q2() const {
	std::cout << "Q2:" << std::endl;
	float floatVal = 100.0f;
	float* floatPtr = &floatVal;
	floatPtr = (float*)100;
	std::cout << (int)floatPtr << std::endl;
	floatPtr += 3;
	std::cout << (int)floatPtr << std::endl;
}

void l4::Q3() const {
	std::cout << "Q3:" << std::endl;
	int* ptrA = new int(90), * ptrB = new int(45);
	std::cout << *ptrA << " - " << *ptrB << std::endl;
	swap(ptrA, ptrB);
	std::cout << *ptrA << " - " << *ptrB << std::endl;
	delete ptrA;
	delete ptrB;
}

void l4::Q4() const {
	std::cout << "Q4:" << std::endl;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printEven(arr);
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