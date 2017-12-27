//HealthBonus.h
#include "Entity.h"

#ifndef __HAELTHBONUS_H__ 
#define __HEALTHBONUS_H__ 

class HealthBonus : public Entity
{
public:
	HealthBonus(float, float);
	void update(float,float);
	void control();
	void SetHp(int, Gtype);
	bool RadiusDamage(float,float);
};

#endif