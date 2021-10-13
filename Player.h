#pragma once
#include <string>

class Player {
public:
	Player(int hps);
	Player(int hps, int* score);
	~Player();
	int hit_points;
	int* score;
	std::string* name;
};