#include "l7.h"
#include <iostream>

void swap(int& a, int& b);
void bubble_sort_ref(int a[], int size);

int nums[10] = { 7, 3, 5, 2, 1, 4, 6, 9, 10, 8 };

l7::l7() {
	this->title = "===============  Lesson 7 ================ < References";
}

void l7::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
}

void l7::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "Reference type must be assigned a lvalue"<< std::endl;
}
void l7::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << 4 << std::endl;
}

void l7::Q3() const {
	std::cout << "Q3:" << std::endl;
	std::cout << "returns the reference of that local variable which will be destroy when the function returns" << std::endl;
}

void l7::Q4() const {
	std::cout << "Q4:" << std::endl;
	int a = 89;
	int b = 64;
	std::cout << a << "-" << b << std::endl;
	swap(a, b);
	std::cout << a << "-" << b << std::endl;
}

void l7::Q5() const {
	std::cout << "Q5:" << std::endl;
	for (int i = 0; i < 10; i++) { std::cout << nums[i] << std::endl; }
	bubble_sort_ref(nums, 10);
	for (int i = 0; i < 10; i++) { std::cout << nums[i] << std::endl; }
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort_ref(int a[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}