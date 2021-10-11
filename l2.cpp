#include "l2.h"
#include <iostream>

void product(int a, int b);
double quotient(double a, int b);
void calculator(double a, double b, char op);

l2::l2() {
	this->title = "===============  Lesson 2 ================ < functions";
}

void l2::ans() const {
	std::cout << this->title <<  std::endl;
	Q1();
	Q2();
	Q3();
}

void l2::Q1() const {
	std::cout << "Q1:" << std::endl;
	product(12, 34);
}
void l2::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << quotient(5, 3) << std::endl;
}

void l2::Q3() const {
	std::cout << "Q3:" << std::endl;
	calculator(100, 3, '/');
}

void product(int a, int b) {
	std::cout << a * b << std::endl;
}

double quotient(double a, int b) {
	return a / b;
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