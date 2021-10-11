#pragma once

class Enemy {
public:
	Enemy(int hps);
	Enemy(int hps, int* sc);
	~Enemy();
	int hit_points;
	int* score;	
};