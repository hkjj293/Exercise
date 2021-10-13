#include "l8.h"
#include <iostream>
#include <time.h>

void print_name(char a[]);
void write_name(char* des[], const char name[], int length);
void battleship(int map_size, int level);
bool** battleship_init(int size);
void terminate_battleship(bool**& map, int size);

l8::l8() {
	this->title = "===============  Lesson 8 ================ < Arrays";
}

void l8::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
}

void l8::Q1() const {
	std::cout << "Q1:" << std::endl;
	char name[] = "Chris Hui";
	print_name(name);
}
void l8::Q2() const {
	std::cout << "Q2:" << std::endl;
	char* first = NULL;
	char* last = NULL;
	write_name(&first, "Chris", 5);
	write_name(&last, "Hui", 3);
	std::cout << first << " " << last << std::endl;
	delete[] first;
	delete[] last;
}

void l8::Q3() const {
	std::cout << "Q3:" << std::endl;
	battleship(5, 4);
}

void print_name(char a[]) {
	std::cout << a << std::endl;
}

void write_name(char* des[], const char name[], int length) {
	//if (des != NULL) delete[] des;
	*des = new char[length + 1];
	(*des)[length] = '\0';
	for (int i = length - 1; i >= 0; i--) {
		(*des)[i] = name[i];
	}
}

void battleship(int map_size, int level) {
	bool** map = battleship_init(map_size);
	int trials = map_size * map_size / level;
	while (trials > 0) {
		std::cout << "You have " << trials << " trials left--" << std::endl;
		std::cout << "please input the X coordinate (0-" << map_size - 1 << "): ";
		int x;
		std::cin >> x;
		std::cout << "please input the Y coordinate (0-" << map_size - 1 << "): ";
		int y;
		std::cin >> y;
		if (map[y][x]) {
			break;
		}
		else {
			std::cout << "Wrong Guess... Try again!" << std::endl;
			trials--;
		}
	}
	if (trials > 0) {
		std::cout << "Perfect Guess... You win!" << std::endl;
	}
	else {
		std::cout << "Wrong Guess... You lose!" << std::endl;
	}
	terminate_battleship(map, map_size);
}

bool** battleship_init(int size) {
	bool** map = new bool* [size];
	for (int i = 0; i < size; i++) {
		map[i] = new bool[size];
		for (int j = 0; j < size; j++) {
			map[i][j] = false;
		}
	}
	srand((int)time(NULL));
	map[rand() % size][rand() % size] = true;
	return map;
}

void terminate_battleship(bool**& map, int size) {
	for (int i = 0; i < size; i++) {
		delete[] map[i];
		map[i] = NULL;
	}
	delete[] map;
	map = NULL;
}