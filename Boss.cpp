#include "Boss.h"
#include <iostream>

Boss::Boss(int hps, int ammo, int armmour) :
	ArmedEnemy(hps,ammo),
	armmour_level(armmour){

}

Boss::~Boss() {
	
}


void Boss::shoot() {
	if (ammo_level > 0)
	{
		std::cout << "bang!\n";
		--ammo_level;
	}
	else
	{
		std::cout << "out of ammo\n";
	}
}

void Boss::hit(int damage) {
	hit_points -= (this->armmour_level <= damage)*(damage - this->armmour_level);
}