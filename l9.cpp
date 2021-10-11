#include "l9.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>

l9::l9() {
	this->title = "===============  Lesson 9 ================ < Classes";
}

void l9::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
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
	delete plr;
}

void l9::Q3() const {
	std::cout << "Q3:" << std::endl;

}

void l9::Q4() const {
	std::cout << "Q4:" << std::endl;

}