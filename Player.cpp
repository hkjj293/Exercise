#include "Player.h"

Player::Player(int hps,int* score) :
	hit_points(hps), score(score) {
	name = NULL;
}

Player::Player(int hps) :
	hit_points(hps) {
	score = new int(0);
	name = NULL;
}

Player::~Player() {
	delete score;
}

