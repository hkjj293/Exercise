#include "Enemy.h"


Enemy::Enemy(int hps,int* sc) :
	hit_points(hps), score(sc) {
	score = new int(0);
}

Enemy::Enemy(int hps) :
	hit_points(hps) {
	score = new int(0);
}

Enemy::~Enemy() {
	delete score;
}

void Enemy::hit(int damage) {
	hit_points -= damage;
}