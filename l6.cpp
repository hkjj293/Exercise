#include "l6.h"
#include <iostream>

void some_function();
namespace p6 {
	void some_function();
}

l6::l6() {
	this->title = "===============  Lesson 6 ================ < Scope";
}

void l6::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
}

void l6::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "When program start and terminate. global variables are embedded with the assembly code while local variables are created with its scope on the stack."<< std::endl;
}
void l6::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << "Inside for loop" << std::endl;
}

void l6::Q3() const {
	std::cout << "Q3:" << std::endl;
	int a = 2;
	{
		int a = 0;
		std::cout << a << std::endl;
	}
	std::cout << a << std::endl;
}

void l6::Q4() const {
	std::cout << "Q4:" << std::endl;
	some_function();
	p6::some_function();
}

void some_function() {
	std::cout << "some function outside p6" << std::endl;
}

void p6::some_function() {
	std::cout << "some function inside p6" << std::endl;
}
