#include "l3.h"
#include <iostream>

bool isPos(int a);
void askTillNeg();
int factorial_recc(int a);

l3::l3() {
	this->title = "===============  Lesson 3 ================ < flow:";
}

void l3::ans() const {
	std::cout << this->title << std::endl;
	Q1();
	Q2();
	Q3();
}

void l3::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << isPos(-23) << " " << isPos(34) << std::endl;
}
void l3::Q2() const {
	std::cout << "Q2:" << std::endl;
	askTillNeg();
}

void l3::Q3() const {
	std::cout << "Q3:" << std::endl;
	std::cout << factorial_recc(10) << std::endl;
}

bool isPos(int a) {
	return a >= 0;
}

void askTillNeg() {
	int a = 0;
	while(isPos(a)){
		std::cout << "Please input an integer" << std::endl;
		std::cin >> a;
	}
}

int factorial_recc(int a) {
	if (a == 1)return 1;
	return a*factorial_recc(a - 1);
}