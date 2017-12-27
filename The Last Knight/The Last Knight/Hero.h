//hero.h
#include "Entity.h"

#ifndef __HERO_H__ 
#define __HERO_H__ 

class Hero : public Entity
{
protected:
	int TimeAction;
	Clock time2;
public:
	Hero();
	void update(float,float);
	void control();
	void SetHp(int, Gtype);
	bool RadiusDamage(float,float);
	float GetSpeed();
	bool TimeOfAction();
	void StartTime2();
	int GetTimeAction();
};

#endif