#include "Entity.h"

#ifndef __HERO_H__ 
#define __HERO_H__ 

class Hero : public Entity
{
public:
	Hero();
	void update(float,float);
	void control();
};

#endif