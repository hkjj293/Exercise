#pragma once

#include "ArmedEnemy.h"

class Boss : public ArmedEnemy
{
public:
	Boss(int hps, int ammo, int armmour);
	virtual ~Boss();
	virtual void shoot();
	virtual void hit(int damage);
	int armmour_level;
};