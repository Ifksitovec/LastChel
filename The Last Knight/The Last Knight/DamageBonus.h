#include "Entity.h"

#ifndef __DAMAGEBONUS_H__ 
#define __DAMAGEBONUS_H__ 

class DamageBonus : public Entity
{
public:
	DamageBonus(float, float);
	void update(float,float);
	void control();
	void SetHp(int);
	bool RadiusDamage(float,float);
};

#endif