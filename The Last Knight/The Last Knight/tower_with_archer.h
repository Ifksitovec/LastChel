#include "Entity.h"

#ifndef __TOWERARCH_H__ 
#define __TOWERARCH_H__ 

class TowerArch : public Entity
{
public:
	TowerArch(float, float);
	void update(float,float);
	void control();
	void SetHp(int);
	bool RadiusDamage(float,float);
};

#endif