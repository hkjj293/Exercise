#pragma once
#include <string>

class Player {
public:
	Player(int hps);
	Player(int hps, int* sc);
	~Player();
	int hit_points;
	int* score;
	std::string* name;
};