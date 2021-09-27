#include <iostream>

void product(int a, int b);
double quotient(double a, int b);
void calculator(double a, double b, char op);
bool isNeg(int a);
void askTillNeg();

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
