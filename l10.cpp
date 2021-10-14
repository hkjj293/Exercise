#include "l10.h"
#include "Boss.h"
#include "ComparableBST.h"
#include "ComparableInt.h"
#include <iostream>

void decrem_hit_point(Enemy& en);

l10::l10() {
	this->title = "===============  Lesson 10 ================ < Inheritance";
}

void l10::ans() const {
	std::cout <<  this->title << std::endl;
	Q1();
	Q2();
	Q3();
	Q4();
	Q5();
}

void l10::Q1() const {
	std::cout << "Q1:" << std::endl;
	std::cout << "When deleting ArmedEnemy, it may only run the base class destructor if we declare the ArmedEnemy as Enemy. This cause by not looking up the vtable." << std::endl;
}
void l10::Q2() const {
	std::cout << "Q2:" << std::endl;
	std::cout << "More virtual functions exist cause longer vtable, longer vtable consume more memory when compile." << std::endl;
}

void l10::Q3() const {
	std::cout << "Q3:" << std::endl;
	Boss* boss = new Boss(100, 12, 30);
	for (int i = 0; i < 20; i++) {
		boss->shoot();
	}
	std::cout << boss->armmour_level << std::endl;
	std::cout << boss->hit_points << std::endl;
	delete boss;
}

void l10::Q4() const {
	std::cout << "Q4:" << std::endl;
	Enemy* enemies[10];// = new Enemy * [10];
	for (int i = 0; i < 5; i++) {
		enemies[i] = new ArmedEnemy(100, 20);
		enemies[i + 5] = new Boss(200, 30, 40);
	}
	for (int i = 0; i < 10; i++) {
		decrem_hit_point(*(enemies[i]));
		std::cout << enemies[i]->hit_points << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete enemies[i];
		enemies[i] = NULL;
	}
}

void l10::Q5() const {
	std::cout << "Q5:" << std::endl;
	ComparableBST* cbst = new ComparableBST();
	srand(1);
	for (int i = 0; i < 3000; i++) {
		ComparableInt* cint = new ComparableInt(rand() % 80 - 40);
		cbst->add_node(cint);
	}
	cbst->print();
	ComparableInt cint = ComparableInt(6);
	std::cout << "6: " << cbst->has_element(cint) << std::endl;
	cint = ComparableInt(50);
	std::cout << "50: " << cbst->has_element(cint) << std::endl;
	delete cbst;
}

void decrem_hit_point(Enemy& en) {
	en.hit(70);
}

