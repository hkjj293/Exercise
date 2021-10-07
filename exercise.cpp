#include "exercise.h"
#include <iostream>

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

void product(int a, int b) {
	std::cout << a * b << std::endl;
}

double quotient(double a, int b) {
	return a / b;
}
