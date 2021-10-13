#include "l9.h"
#include "Enemy.h"
#include "Player.h"
#include "Battleship.h"
#include "BST.h"
#include <iostream>

bool** bs_init(int size);
void bs_terminate(bool**& map, int size);
void battleship_game(int map_size, int level);
void print_map(bool**& map, int size, bool hit);

l9::l9() {
	this->title = "===============  Lesson 9 ================ < Classes";
}

void l9::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
}

void l9::Q1() const {
	std::cout << "Q1:" << std::endl;
	Enemy* en = new Enemy(100, new int(20));
	std::cout << *(en->score) << std::endl;
	delete en;
}
void l9::Q2() const {
	std::cout << "Q2:" << std::endl;
	Player* plr = new Player(100, new int(20));
	plr->name = new std::string("Chris");
	std::cout << *(plr->name) << std::endl;
	delete plr;
}

void l9::Q3() const {
	std::cout << "Q3:" << std::endl;
	BST* bst = new BST();
	srand(1);
	for (int i = 0; i < 3000; i++) {
		bst->add_node(rand()%80-40);
	}
	bst->print();
	std::cout << "6: " << bst->has_element(6) << std::endl;
	std::cout << "50: " << bst->has_element(50) << std::endl;
	delete bst;
}

void l9::Q4() const {
	std::cout << "Q4:" << std::endl;
	battleship_game(2, 1);
}

void battleship_game(int map_size, int level) {
	bool** map = bs_init(map_size);
	int trials = map_size * map_size / level;
	bool hit = false;
	Battleship* bs = new Battleship(300);
	while (trials > 0 && bs->hit_points > 0) {
		print_map(map, map_size, hit);
		std::cout << "Score: " << bs->score << " -- You have " << trials << " trials left--" << std::endl;
		std::cout << "Battleship still have " << bs->hit_points << " hps left--" << std::endl;
		std::cout << "please input the X coordinate (0-" << map_size - 1 << "): ";
		int x;
		std::cin >> x;
		std::cout << "please input the Y coordinate (0-" << map_size - 1 << "): ";
		int y;
		std::cin >> y;
		if (map[y][x]) {
			hit = true;
			bs->hit_points -= 100;
			bs->score += 1000;
			std::cout << "Boom! Target hit!" << std::endl;
		}
		else {
			std::cout << "Wrong Guess... Try again!" << std::endl;
			trials--;
		}
		std::cout << std::endl;
	}
	if (trials > 0) {
		std::cout << "Battleship sunk... You win!   Score: " << bs->score << std::endl;
	}
	else {
		std::cout << "Battleship alive... You lose!" << std::endl;
	}
	bs_terminate(map, map_size);
	delete bs;
}

void print_map(bool**& map, int size, bool hit){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << map[i][j] * hit;
		}
		std::cout << std::endl;
	}
}

bool** bs_init(int size) {
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

void bs_terminate(bool**& map, int size) {
	for (int i = 0; i < size; i++) {
		delete[] map[i];
		map[i] = NULL;
	}
	delete[] map;
	map = NULL;
}