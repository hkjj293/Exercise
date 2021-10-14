#include "l11.h"
#include <iostream>
#include "Matrix.h"

void set_matrix(Matrix<char>& ch);
void print_matrix(Matrix<char>& ch);

l11::l11() {
	this->title = "===============  Lesson 11 ================ < Template";
}

void l11::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
}

void l11::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "When there is a class initiated." << std::endl;
}
void l11::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << "Compiler need to know all the use of that template, so you would place the definitiion in the header files" << std::endl;
}

void l11::Q3() const {
	std::cout << "Q3:" << std::endl;
	Matrix<char>* ch = new Matrix<char>();
	set_matrix(*ch);
	print_matrix(*ch);
	delete ch;
	ch = NULL;
}

void l11::Q4() const {
	std::cout << "Q4:" << std::endl;
}

void l11::Q5() const {
	std::cout << "Q5:" << std::endl;

}

void set_matrix(Matrix<char>& ch) {
	for (int i = 0; i < ch.x_size; i++) {
		for (int j = 0; j < ch.y_size; j++) {
			ch.cells[i][j] = (char)(((int)'a') + i * 3 + j);
		}
	}
}


void print_matrix(Matrix<char>& ch) {
	for (int i = 0; i < ch.x_size; i++) {
		for (int j = 0; j < ch.y_size; j++) {
			std::cout << ch.cells[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
