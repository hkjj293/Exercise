#include "l1.h"
#include <iostream>

l1::l1() {
	this->title = "===============  Lesson 1 ================ < Hello World";
}

void l1::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
}

void l1::Q1() const {
	std::cout << "Q1:" << std::endl;
	unsigned int a = -8;
	std::cout << a << std::endl;
}
void l1::Q2() const {
	std::cout << "Q2:" << std::endl;
	char a = 'a';
	bool b = true;
	double c = 3.342343;
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
}

void l1::Q3() const {
	std::cout << "Q3:" << std::endl;
	std::cout << "Please Enter two numbers" << std::endl;
	int b, c;
	std::cin >> b;
	std::cin >> c;
	std::cout << c + b << std::endl << c * b << std::endl;
}

void l1::Q4() const {
	std::cout << "Q4:" << std::endl;
	std::string name;
	std::cout << "Enter your name" << std::endl;
	std::cin >> name;
	std::cout << "Hello " << name << "!" << std::endl;
}