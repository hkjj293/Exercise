#pragma once

class Enemy {
public:
	Enemy(int hps);
	Enemy(int hps, int* sc);
	virtual void hit(int damage);
	virtual ~Enemy();
	int hit_points;
	int* score;	
};