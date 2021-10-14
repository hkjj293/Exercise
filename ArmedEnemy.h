#pragma once

#include "Enemy.h"

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual void shoot();
protected:
	int ammo_level;
};