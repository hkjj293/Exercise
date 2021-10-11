#include "Player.h"


Player::Player(int hps,int* sc) :
	hit_points(hps), score(sc) {
	score = new int(0);
}

Player::Player(int hps) :
	hit_points(hps) {
	score = new int(0);
}

Player::~Player() {
	delete score;
}

